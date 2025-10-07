/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __LISTS_H__
#define __LISTS_H__

/********* Bi-directional list operations ********/
/* Bi-directional list structure */
struct bi_list_node_t {
    struct bi_list_node_t *bprev;
    struct bi_list_node_t *bnext;
};

/* Init an empty node. */
#define BI_LIST_INIT_NODE(node)                   \
    do {                                          \
    if ((node) != NULL) {                         \
        (node)->bnext = (node);                   \
        (node)->bprev = (node);                   \
    }                                             \
} while (0)

/* Insert a new node after current node: (bnext) of current. */
#define BI_LIST_INSERT_AFTER(curr, node) do {     \
    if ((curr) != NULL && (node) != NULL &&       \
        (curr)->bnext != NULL) {                  \
        (node)->bnext = (curr)->bnext;            \
        (node)->bprev = (curr);                   \
        (curr)->bnext->bprev = (node);            \
        (curr)->bnext = (node);                   \
    }                                             \
} while (0)

/* Add one node into list as the tail: (bprev) of head. */
#define BI_LIST_INSERT_BEFORE(curr, node) do {    \
    if ((curr) != NULL && (node) != NULL &&       \
        (curr)->bprev != NULL) {                  \
        (curr)->bprev->bnext = (node);            \
        (node)->bprev = (curr)->bprev;            \
        (curr)->bprev = (node);                   \
        (node)->bnext = (curr);                   \
    }                                             \
} while (0)

/* Remove one node from the list. */
#define BI_LIST_REMOVE_NODE(node) do {            \
    if ((node) != NULL &&                         \
        (node)->bprev != NULL &&                  \
        (node)->bnext != NULL) {                  \
        (node)->bprev->bnext = (node)->bnext;     \
        (node)->bnext->bprev = (node)->bprev;     \
    }                                             \
} while (0)

/* Is the head empty? */
#define BI_LIST_IS_EMPTY(head)      \
    (((head) == NULL) || ((head)->bnext == (head)))

/* The node's next node. */
#define BI_LIST_NEXT_NODE(node)     \
    (((node) != NULL) ? ((node)->bnext) : NULL)

/* Go through each node of a list. */
#define BI_LIST_FOR_EACH(node, head)                                \
    for (node = (((head) != NULL) ? (head)->bnext : NULL);          \
        ((head) != NULL) && ((node) != NULL) && (node != (head));   \
         node = (node)->bnext)

/********* Uni-directional list operations ********/
/* Initialize the head node. */
#define UNI_LIST_INIT_NODE(head, link) do {             \
    if ((head) != NULL) {                               \
        (head)->link = NULL;                            \
    }                                                   \
} while (0)

/* Insert a new node after given position node. */
#define UNI_LIST_INSERT_AFTER(posi, node, link) do {    \
    if ((posi) != NULL && (node) != NULL) {             \
        (node)->link = (posi)->link;                    \
        (posi)->link = (node);                          \
    }                                                   \
} while (0)

/* Is list empty? */
#define UNI_LIST_IS_EMPTY(node, link)                   \
    ((node) == NULL) || ((node)->link == NULL)

/* Pick the next node. */
#define UNI_LIST_NEXT_NODE(node, link)                  \
    (((node) != NULL) ? ((node)->link) : NULL)

/* Remove one node from the list. */
#define UNI_LIST_REMOVE_NODE(prev, node, link) do {     \
    if ((prev) != NULL && (node) != NULL) {                       \
        (prev)->link = (node)->link;                    \
        (node)->link = NULL;                            \
    }                                                   \
} while (0)

/* Remove node by its pointer ('pointer = &prev_of_node->link'). */
#define UNI_LIST_REMOVE_NODE_BY_PNODE(pnode, link)      \
    do {                                                \
        if ((pnode) != NULL && *(pnode) != NULL) {      \
            *(pnode) = (*(pnode))->link;                \
        }                                               \
    } while (0)

/* Move a node after posi node. */
#define UNI_LIST_MOVE_AFTER(posi, prev, node, link) do {\
    if ((posi) != NULL && (prev) != NULL &&             \
        (node) != NULL) {                               \
        (prev)->link = (node)->link;                    \
        (node)->link = (posi)->link;                    \
        (posi)->link = node;                            \
    }                                                   \
} while (0)

/* Go through each node of a list. */
#define UNI_LIST_FOREACH(node, head, link)                  \
    for (node = (((head) != NULL) ? (head)->link : NULL);   \
         node != NULL;                                      \
         node = (node)->link)

/* Go through each node of a list with prev node recorded. */
#define UNI_LIST_FOREACH_NODE_PREV(prev, node, head, link)              \
    for (prev = NULL, node = (((head) != NULL) ? (head)->link : NULL);  \
         node != NULL;                                          \
         prev = node, node = (prev)->link)

/* Go through each node of a list with recording node and its holder. */
#define UNI_LIST_FOREACH_NODE_PNODE(pnode, node, head, link) \
    for (pnode = (((head) != NULL) ? &(head)->link : NULL),  \
         node = (((head) != NULL) ? (head)->link : NULL);    \
         node != NULL;                                       \
         pnode = &(node)->link, node = (node)->link)

#endif /* __LISTS_H__ */
