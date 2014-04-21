#ifndef __SPOOKYHASH2__
#define __SPOOKYHASH2__

//
// SpookyHash: a 128-bit noncryptographic hash function
// By Bob Jenkins, public domain
//   Oct 31 2010: alpha, framework + SpookyHash::Mix appears right
//   Oct 31 2011: alpha again, Mix only good to 2^^69 but rest appears right
//   Dec 31 2011: beta, improved Mix, tested it for 2-bit deltas
//   Feb  2 2012: production, same bits as beta
//   Feb  5 2012: adjusted definitions of uint* to be more portable
//   Mar 30 2012: 3 bytes/cycle, not 4.  Alpha was 4 but wasn't thorough enough.
//   August 5 2012: SpookyV2 (different results)
// 
// Up to 3 bytes/cycle for long messages.  Reasonably fast for short messages.
// All 1 or 2 bit deltas achieve avalanche within 1% bias per output bit.
//
// This was developed for and tested on 64-bit x86-compatible processors.
// It assumes the processor is little-endian.  There is a macro
// controlling whether unaligned reads are allowed (by default they are).
// This should be an equally good hash on big-endian machines, but it will
// compute different results on them than on little-endian machines.
//
// Google's CityHash has similar specs to SpookyHash, and CityHash is faster
// on new Intel boxes.  MD4 and MD5 also have similar specs, but they are orders
// of magnitude slower.  CRCs are two or more times slower, but unlike 
// SpookyHash, they have nice math for combining the CRCs of pieces to form 
// the CRCs of wholes.  There are also cryptographic hashes, but those are even 
// slower than MD5.
//

//
// SpookyHash: hash a single message in one call, produce 128-bit output
// @message: Message to hash
// @length: Length of message in bytes
// @hash1: in/out. in seed 1, out hash value 1.
// @hash2: in/out. in seed 2, out hash value 2.
//
// For shorter seeds or results, initialize seed1 and seed2 to the 32-bit or
// 64-bit seed material, and truncate hash1 to get the desired hash size.
//
void SpookyHash128(const void *message, size_t length, uint64_t *hash1,
    uint64_t *hash2);

#endif
