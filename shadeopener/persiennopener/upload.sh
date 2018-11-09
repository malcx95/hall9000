#!/bin/bash

scp -r ./* pi@rpi:/home/pi/hall9000/shadeopener/persiennopener

if [ $? -ne 0 ]; then
    echo "Upload failed"
    exit 1
fi

