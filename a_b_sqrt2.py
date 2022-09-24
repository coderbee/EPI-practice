import Math
from typing import List

import bintrees

from test_framework import generic_test

# These numbers have a very interesting property, called ugly numbers.

class Number: 
  def __init__(self, a, b): 
    self.a, self.b = a,b
    self.val = a + b * math.sqrt(2)
   
  def __lt__(self, other):
    return self.val < other.val
  
  def __eq__(self, other
