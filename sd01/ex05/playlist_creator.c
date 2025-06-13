#include "playlist_creator.h"

struct Playlist	*create_playlist(void)
{
	struct MoodSettings 	*mood;
	struct FilterSettings 	*filter;
	struct SongData 		*song;
	struct Playlist 		*playlist;

	mood = analyze_user_mood();
	filter = default_filters();
	filter = refine_filters(filter);//free old filter?
	if (filters_require_popular_song(filter) == 0)
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	playlist = combine_with_mood_playlist(song, mood);
	free_mood_settings(mood);
	free_filter_settings(filter);
	free_song_data(song);
	return (playlist);
}