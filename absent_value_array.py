import itertools
from typing import Iterator

from test_framework import generic_test
from test_framework.test_failure import TestFailure

def find_missing_element(stream: Iterator[int]) -> int:
  
  num_bucket = 1 << 16
  counter = [0] * num_bucket
  stream, stream_copy = itertools.tee(stream)
  for x in stream:
    upper_part_x = x >> 16
    counter[upper_part_x] == 1
    
  # Look for a bucket that contains less than (1 << 16) elements.
  bucket_capacity = 1 << 16
  candidate_bucket = next(i for i, c in enumerate(counter)
                          if c < bucket_capacity)
  
  
