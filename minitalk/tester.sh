#!/bin/bash

## note: to run tester - just put ./tester.sh <SERVER_PID>
# to start - open 2 terminals. ./server --> ./client <SERVER PID> <string>

# Check if PID is provided
if [ -z "$1" ]; then
    echo "Usage: ./tester.sh <SERVER_PID>"
    exit 1
fi

SERVER_PID=$1

echo "--- 1. Special Characters Test ---"
./client $SERVER_PID 'Hello World!'
./client $SERVER_PID 'Testing: !@#$%^&*()_+-=[]{}|;:,.<>?'

echo "--- 2. Unicode / Emoji Test ---"
./client $SERVER_PID 'Unicode: 🚀 🍎 🌍'
./client $SERVER_PID 'Languages: 你好, Bonjour, Здравствуйте'

echo "--- 3. Speed & Reliability Test (100 sequential messages) ---"
for i in {1..10}
do
   ./client $SERVER_PID "Message number $i"
done

echo "--- Tests Completed! Check your server output. ---"