#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	struct MusicLibrary *lib;
	char **mlist;
	int i;

	lib = create_music_library();
	mlist = scan_directory(directory_path);
	if (!mlist)
	  return (NULL);
	i = 0;
	while (mlist[i])
	{
		 update_music_library(lib, process_music_file(directory_path, mfile[i]));
		 ++i;
	}
	return (lib);
}