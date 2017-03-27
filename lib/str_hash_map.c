/* Title: str_hash_map.c
 * Description: Implementation of a hash map which stores c strings
 * Author: Matthew Westphall, Winor Chen
 */

#include <stdlib.h>
#include <string.h>
#include "../include/str_hash_map.h"
#include "../include/strhash.h"

void free_hash_map(str_hash_map * map)
{
	for(int index = 0; index < map->list_size; index++)
	{
		free(map->list+index);
	}
}

void map_add(char * string, str_hash_map * map)
{
	size_t index = strhash(string);
	str_hash_node * current_node = ((map -> list)+index);
	str_hash_node * new_node = malloc(sizeof(str_hash_node));
	new_node -> data = malloc(strlen(string)+1);
	strcpy(new_node->data, string);

	// Special case, if direct mapping leads to empty element in map
	if(current_node == NULL)
	{
		current_node = new_node; //Link in node directly
		current_node -> bucket_succ_count = 0;
	}

	// General case, already a node present
	else
	{
		new_node -> next = current_node;
		new_node -> bucket_succ_count = current_node -> bucket_succ_count + 1;
		current_node = new_node; // Link in last node
	}
}

word_list map_peek(char * string, str_hash_map * map)
{
	size_t index = strhash(string);
	size_t bucket_size = ((map -> list)+index)->bucket_succ_count + 1;
	word_list words = malloc(bucket_size * sizeof(char*));
	str_hash_node * current_node = ((map ->list)+index);
	
	int word_list_index = 0;
	while(current_node != NULL){
		*(words+word_list_index) = current_node->data;
		word_list_index++;
		current_node = current_node->next;
	}

	return words;
}
