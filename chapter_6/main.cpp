#include <iostream>
#include "gift_list.h"

int main() {

    GiftList gl = GiftList();

    gl.add_gift("raleigh", "apple");

    gl.add_gift("raleigh", "banana");

    gl.add_gift("raleigh", "cake");

    gl.add_gift("kevin", "alpha");

    gl.add_gift("kevin", "bravo");

    gl.delete_gift("kevin", "alpha");

    gl.delete_gift("raleigh", "banana");

    gl.list_gifts("raleigh");

    gl.list_gifts("kevin");


    gl.delete_gift("raleigh", "apple");

    gl.list_gifts("raleigh");

    gl.delete_user("kevin");

    gl.list_gifts("kevin");

    gl.list_users();


}
