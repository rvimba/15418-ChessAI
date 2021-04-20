
struct move_header {
    int8_t rank_source;
    int8_t file_source;
    int8_t rank_dest;
    int8_t file_dest;
};
typedef struct move_header move_pointer;
typedef move_pointer* move_t;
