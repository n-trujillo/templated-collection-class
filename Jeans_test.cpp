#include <iostream>
#include <fstream>
#include <sstream>
#include "Jeans.h"
#include "Collection.h"
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c) {
  for (int i = 0; i < 10; i++) {
    string strJeansColor = "";
    string strJeansSize = "";

    Jeans_colors JeansColor;
    Jeans_sizes JeansSize;

    int colorCase = 0;
    int sizeCase = 0;

    // get info
    is >> strJeansColor >> strJeansSize;

    // determine color case
    if (strJeansColor == "white") {
      colorCase = 0;
    }

    if (strJeansColor == "black") {
      colorCase = 1;
    }

    if (strJeansColor == "blue") {
      colorCase = 2;
    }

    if (strJeansColor == "grey") {
      colorCase = 3;
    }


    // determine size case
    if (strJeansSize == "small") {
      sizeCase = 0;
    }

    if (strJeansSize == "medium") {
      sizeCase = 1;
    }

    if (strJeansSize == "large") {
      sizeCase = 2;
    }

    if (strJeansSize == "xlarge") {
        sizeCase = 3;
    }

    switch(colorCase) {
      case 0:
        JeansColor = Jeans_colors::white;
        break;
      case 1:
        JeansColor = Jeans_colors::black;
        break;
      case 2:
        JeansColor = Jeans_colors::blue;
        break;
      case 3:
        JeansColor = Jeans_colors::grey;
        break;
    }

    switch(sizeCase) {
      case 0:
        JeansSize = Jeans_sizes::small;
        break;
      case 1:
        JeansSize = Jeans_sizes::medium;
        break;
      case 2:
        JeansSize = Jeans_sizes::large;
        break;
      case 3:
        JeansSize = Jeans_sizes::xlarge;
        break;
    }

    // create new ball
    Jeans j = Jeans(JeansColor, JeansSize);

    // add ball to the collection
    c.insert_item(j);
  }

  // return input
  return is;
}

void test_jeans(){
        Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
        Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
        Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
        Jeans jeans_4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
        CollectionJN collection_0;
        CollectionJN collection_1;
        CollectionJN collection_2(3);
        CollectionJN collection_3(5);
        CollectionJN collection_file(1);
        collection_0.insert_item(jeans_1);
        collection_0.make_empty();
        collection_1.insert_item(jeans_1);
        collection_2.insert_item(jeans_2);
        
        collection_2.print_items();
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        CollectionJN collection_copy(collection_1);
        collection_1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        CollectionJN collection_7 = move(collection_1);
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.remove_this_item(jeans_2);
        
        collection_2.print_items();
        collection_copy.make_empty();
        if(collection_2.is_empty()){
            collection_2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        }
        ifstream ifs("jeans1.data");
        ifs >> collection_file;
        collection_file.insert_item(jeans_3);
        collection_file.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_2);
        collection_2.insert_item(jeans_1);
        
        collection_file.print_items();
      
                    swap(collection_file,collection_2);
                    collection_3 = make_union(collection_file,collection_2);                
                     if((collection_3.total_items() - collection_2.total_items()) == collection_file.total_items()){
                          sort_by_size(collection_2,Sort_choice::selection_sort);
                          cout<<collection_3;
                     }
}
