#include <stdio.h>
#include "semver.h"

  int
main( int argc, char * argv[] )
{
  semver_t current_version = {0};
  semver_t compare_version = {0};
  char * current = argv[1];
  char * compare = argv[2];

  if ( semver_parse( compare, & current_version ) ||
       semver_parse( current, & compare_version )
     )
    {
      fprintf( stderr, "Invalid semver string\n" );
      return -1;
    }

  int resolution = semver_compare( compare_version, current_version );

  if (resolution == 0)
    {
      printf( "Versions %s is equal to: %s\n", compare, current );
    }
  else if ( resolution == -1)
    {
      printf("Version %s is lower than: %s\n", compare, current );
    }
  else
    {
      printf( "Version %s is higher than: %s\n", compare, current );
    }

  /* Free allocated memory when we're done */
  semver_free( & current_version );
  semver_free( & compare_version );
  return 0;
}
