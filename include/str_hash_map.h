/* Title: str_hash_map.h
 * Description: Declarations for types used for str_hash_map
 * Author: Matthew Westphall, Winor Chen
 */

/* Type: struct
 * Name: str_hash_node
 * Description: node which holds a string and the next string in the bucket
 * Field(s):
 *	char * data - pointer to string accessible at the hashed node
 *	str_hash_node * next - pointer to the next node in the bucket
 *	int bucket_succ_count - number of elements after this element
 *				in the node chain
 *
 */
typedef struct str_hash_node
{
	char * data;
	struct str_hash_node * next;
	int bucket_succ_count;
} str_hash_node;

/* Type: struct
 * Name: str_hash_map
 * Description: a hash map with an array of str_hash_nodes
 * Fields: 
 *	str_hash_node * node_list - array where nodes are hashed to
 *	int list_size - size of the array
 *	int word_count - amount of words mapped in the array
 */
typedef struct str_hash_map
{
	str_hash_node * list;
	int list_size;
	int word_count;
} str_hash_map;

/* Type: char**
 * Name: word_list
 * Description: an array of strings
 */
typedef char** word_list;

/* Type: routine
 * Name: free_hash_map
 * Description: frees up the memory used by a str_hash_map
 * Parameter(s):
 *	str_hash_map map - map to free
 */
void free_hash_map(str_hash_map * map);

/* Type: routine
 * Name: map_add
 * Description: adds a string to hash map
 * Parameters(s):
 *	char * string - string to hash into the map
 *	str_hash_map * map - map to hash into
 */
void map_add(char * string, str_hash_map * map);

/* Type: routine
 * Name: map_peek
 * Description: returns a pointer to a 2d array with a list of strings
 * 		who share the same hash
 * Parameter(s):
 *	char * string - string that defines the hash used to peek
 *	str_hash_map * map - map to retrieve strings from
 * Returns:
 *	word_list words - the list of strings that all hash to the same
 *			  location
 */
word_list map_peek(char * string, str_hash_map * map);
