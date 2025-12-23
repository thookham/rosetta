import os
import sys
import subprocess

# Get the directory where this script resides (source/)
script_dir = os.path.dirname(os.path.abspath(__file__))

# Define the path to the actual SCons script
scons_path = os.path.join(script_dir, "external", "scons-local", "scons.py")

# Check if file exists
if not os.path.exists(scons_path):
    print(f"Error: Could not find SCons at {scons_path}")
    sys.exit(1)

# Forward execution to the actual scons script
# We use sys.executable to ensure we use the same python interpreter
cmd = [sys.executable, scons_path] + sys.argv[1:]

try:
    # Use subprocess.call to execute and wait
    # We exit with the same return code
    ret = subprocess.call(cmd)
    sys.exit(ret)
except Exception as e:
    print(f"Error executing SCons: {e}")
    sys.exit(1)