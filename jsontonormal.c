#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

int main(){
json_t *root;
json_error_t error;


    root = json_load_file("h.json", 0, &error);

if ( !root )
{
    fprintf( stderr, "error: on line %d: %s\n", error.line, error.text );
    return 1;
}

const char *key;
json_t *value;

void *iter = json_object_iter( root );
while( iter )
{
    key = json_object_iter_key(iter);
    value = json_object_iter_value(iter);

    printf("Key: %s, Value: %s\n", key, json_string_value(value) );

    iter = json_object_iter_next(root, iter);
}

json_decref(root);

	return 0;
}
