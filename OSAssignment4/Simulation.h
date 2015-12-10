#ifndef SIM_H_
#define SIM_H_

/*
 * Both CACHE_SIZE and BLOCK_SIZE are in bytes. We can calculate the number
 * of lines in the cache with CACHE_SIZE / BLOCK_SIZE.
 */

/* Print Debug Messages */
#define DEBUG 0

/* Max Line Length in Trace */
#define LINELENGTH 128

/* Change Block size and Cache Sizes (in bytes) here */
#define CACHE_SIZE 16384
#define BLOCK_SIZE 4

#define TAG 18 /* 18 + 0 = 18 */
#define INDEX 12 /* 18 + 12 = 30 */
#define OFFSET 2 /* 30 + 2 = 32 */


typedef struct Cache_* Cache;
typedef struct Block_* Block;

Cache createCache(int cache_size, int block_size, int write_policy);
void destroyCache(Cache cache);
int readFromCache(Cache cache, char* address);

int writeToCache(Cache cache, char* address);
void printCache(Cache cache);
#endif
