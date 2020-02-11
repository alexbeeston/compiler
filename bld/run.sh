#!/bin/bash
cmake ..
make
cat ../script.cpsl | ./calc
