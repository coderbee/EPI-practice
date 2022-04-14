long long Gcd(long long x, long long y) {
  if( x > y ) {
    return Gcd(y,x);
  } else if (x == 0 ) {
    return y;
  } else if (!(x & 1) && !(y & 1)) {  // x and y are even.
    return Gcd(x >> 1, y >> 1 ) << 1;
  } else if (!(x & 1) && y & 1) {   //x is even, y is odd.
    return Gcd(x >> 1, y);
  } else if (x & 1 && !(y & 1)) {   // x is odd, y is even.
    return Gcd(x, y >>1);
  }
  return Gcd(x, y - x); // Both x and y are odd.
}
