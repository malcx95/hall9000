#!/bin/sh
cd frontend/quickstart
ng build
cd ../../backend
lein run
