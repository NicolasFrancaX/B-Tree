#include "btree_util.h"

node_position _node_position_new(node_t *node, uint indice) {
        node_position node_pos = {.node = node, .indice = indice};

        return node_pos;
}

pair_t* _pair_new(int key, void *value) {
        pair_t *p = malloc(sizeof(pair_t));

        assert(p != NULL);

        #if DEBUG
        printf("allocated new pair with key: %d\n", key);
        #endif

        p->key = key;
        p->value = value;

        return p;
}

pair_t* _pair_copy(pair_t *p) {
        pair_t *new = _pair_new(p->key, p->value);
        return new;
}

node_t* _node_new(uint order, int is_leaf) {
        node_t *n = malloc(sizeof(node_t));
        assert(n != NULL);

        #if DEBUG
        printf("allocated new node\n");
        #endif

        n->n_keys = 0;
        n->is_leaf = is_leaf;
        n->keys = malloc((2*order-1) * sizeof(pair_t));
        n->children = malloc((2*order) * sizeof(node_t*));

        return n;
}
