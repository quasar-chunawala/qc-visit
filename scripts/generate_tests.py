"""generate_tests.py

Generates .cpp files that instantiate std::visit / qc::flat_array::visit / qc::multidim_array::vist
over N-alternative variants, for a range of N, so compile-time can be swept with hyprfine.
"""

import argparse
import json
import os
import sys
from pathlib import Path
