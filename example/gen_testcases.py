#!/usr/bin/env python
"""
Generate AFL testcase input for function call parameters.
"""

import os
import sys

sys.path.insert(0,'../')

import gen

FUNC1 = 0
TCDIR = 'testcases'
FNAME = TCDIR + '/base.dat'

def main():

    if not os.path.exists(TCDIR):
        os.makedirs(TCDIR)

    call = (FUNC1,
             0x10005,
             1 << 5,
             2,
             2,
			 15,
             0
             )
    gen.writeFn(FNAME, gen.mkSyscalls(call, call))

if __name__ == '__main__':
    main()
