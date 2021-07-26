#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
import sys
import time

from tqdm import tqdm

INT_RANGE = 2147483648
RANGE_LIMIT = INT_RANGE >> 4

N = int(1e6)
M = int(1e4)
P = int(2e5)
Q = int(1e2)

keys = random.sample(range(-INT_RANGE, INT_RANGE), k=N)
values = random.choices(range(-INT_RANGE, INT_RANGE), k=N)

points = random.choices(keys, k=M)

new_keys = random.choices(keys, k=P)
new_values = random.choices(range(-INT_RANGE, INT_RANGE), k=P)

ranges_left = random.choices(range(-INT_RANGE, 0), k=Q)
ranges_right = list(map(lambda x: random.randint(
    x, min(INT_RANGE - 1, x + RANGE_LIMIT)), ranges_left))

ranges = list(zip(ranges_left, ranges_right))

with open(sys.argv[1], 'w') as f:
    f.write(f'{N} {M} {P} {Q}\n')
    for k, v in zip(keys, values):
        f.write(f'{k} {v}\n')
    for k in points:
        f.write(f'{k}\n')
    for k, v in zip(new_keys, new_values):
        f.write(f'{k} {v}\n')
    for l, r in ranges:
        f.write(f'{l} {r}\n')

tic = time.time()

pool = dict(zip(keys, values))

point_results = list(map(pool.get, points))

pool.update(zip(new_keys, new_values))


def range_search(l, r):
    s = 0
    for k in tqdm(range(l, r)):
        if k in pool:
            s += 1
    return s


range_results = list(map(lambda x: range_search(*x), tqdm(ranges)))

toc = time.time()
print(f'{toc - tic:.2f}s')

with open(sys.argv[2], 'w') as f:
    for value in point_results:
        f.write(f'{value}\n')
    for ans in range_results:
        f.write(f'{ans}\n')
