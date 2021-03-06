#!/usr/bin/env bash
# sends the signal SIGQUIT to a process, given its PID

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <pid>"
    exit 1
fi
kill -s QUIT "$1"
