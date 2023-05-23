#include "prefix_tree.h"

void test_prefix_tree(void)
{
    Trie prefix_tree = Trie();

    // cout << "test trie node init : ";
    // for (int i = 0; i < 26; i++)
    // {
    //     if ((*prefix_tree.root)->next[i] == nullptr)
    //     {
    //         cout << "null, ";
    //     }
    // }
    // cout << endl;

    cout << "start to test prefix tree insert" << endl;
    prefix_tree.insert_str("abcdefg");
    prefix_tree.insert_str("abc");
    prefix_tree.insert_str("abc");
    prefix_tree.insert_str("bc");
    prefix_tree.insert_str("abc");
    prefix_tree.insert_str("dabc");

    cout << "'abc' has been mentioned " << prefix_tree.search_str("abc") << " times in this tree" << endl;

    cout << "start to test prefix tree delete" << endl;
    cout << "delete 'abc' ?" << (prefix_tree.delete_str("abc") ? "true" : "false") << endl;
    cout << "'abc' has been mentioned " << prefix_tree.search_str("abc") << " times in this tree" << endl;
}