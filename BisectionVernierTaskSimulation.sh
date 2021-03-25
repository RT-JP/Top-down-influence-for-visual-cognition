#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

rm *.csv

./Bisection-izhikevich-100trials.sh

./Vernier-izhikevich-100trials.sh

./ai_graph.sh