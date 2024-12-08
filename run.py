#!/usr/bin/env python3
import json
import sys
import os
import subprocess

def load_config():
    with open('package.json', 'r') as f:
        return json.load(f)

def run_script(config, script_name):
    if script_name not in config['scripts']:
        print(f"Error: Script '{script_name}' not found")
        print("Available scripts:")
        for script in config['scripts']:
            print(f"  - {script}")
        return 1
    
    # Create build directory if it doesn't exist
    os.makedirs('build', exist_ok=True)
    
    # Get the command and add compiler flags if it's a build command
    command = config['scripts'][script_name]
    if 'build' in script_name:
        flags = ' '.join(config['compiler']['flags'])
        std_flag = f"-std={config['compiler']['cpp_standard']}"
        command = command.replace('g++', f'g++ {std_flag} {flags}')
    
    # Execute the command
    try:
        subprocess.run(command, shell=True, check=True)
        return 0
    except subprocess.CalledProcessError as e:
        print(f"Error executing script: {e}")
        return e.returncode

def main():
    if len(sys.argv) < 2:
        print("Usage: ./run.py <script_name>")
        print("Available commands:")
        print("  build      - Compile the project")
        print("  run       - Run the compiled program")
        print("  build:run - Compile and run")
        print("  clean     - Clean build directory")
        print("  debug     - Build with debug symbols")
        return 1
    
    try:
        config = load_config()
        return run_script(config, sys.argv[1])
    except FileNotFoundError:
        print("Error: package.json not found")
        return 1
    except json.JSONDecodeError:
        print("Error: Invalid JSON in package.json")
        return 1

if __name__ == '__main__':
    sys.exit(main())
