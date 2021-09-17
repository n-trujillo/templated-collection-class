#include <iostream>
#include <fstream>
#include <sstream>
#include "Stress_ball.h"
#include "Collection.h"
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

istream& operator>>(istream& is, CollectionSB& c) {
  for (int i = 0; i < 10; i++) {
    string strBallColor = "";
    string strBallSize = "";

    Stress_ball_colors ballColor;
    Stress_ball_sizes ballSize;

    int colorCase = 0;
    int sizeCase = 0;

    // get info
    is >> strBallColor >> strBallSize;

    // determine color case
    if (strBallColor == "red") {
      colorCase = 0;
    }

    if (strBallColor == "blue") {
      colorCase = 1;
    }

    if (strBallColor == "yellow") {
      colorCase = 2;
    }

    if (strBallColor == "green") {
      colorCase = 3;
    }


    // determine size case
    if (strBallSize == "small") {
      sizeCase = 0;
    }

    if (strBallSize == "medium") {
      sizeCase = 1;
    }

    if (strBallSize == "large") {
      sizeCase = 2;
    }

    switch(colorCase) {
      case 0:
        ballColor = Stress_ball_colors::red;
        break;
      case 1:
        ballColor = Stress_ball_colors::blue;
        break;
      case 2:
        ballColor = Stress_ball_colors::yellow;
        break;
      case 3:
        ballColor = Stress_ball_colors::green;
        break;
    }

    switch(sizeCase) {
      case 0:
        ballSize = Stress_ball_sizes::small;
        break;
      case 1:
        ballSize = Stress_ball_sizes::medium;
        break;
      case 2:
        ballSize = Stress_ball_sizes::large;
        break;
    }

    // create new ball
    Stress_ball ball = Stress_ball(ballColor, ballSize);

    // add ball to the collection
    c.insert_item(ball);
  }

  // return input
  return is;
}

void test_stress_balls(){
        Stress_ball stress_ball_1 = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large);
        Stress_ball stress_ball_2 = Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::large);
        Stress_ball stress_ball_3 = Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small);
        Stress_ball stress_ball_4 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);
        CollectionSB collection_1;
        CollectionSB collection_2(3);
        CollectionSB collection_3(5);
        CollectionSB collection_file(1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_4);
        collection_1.insert_item(stress_ball_1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        CollectionSB collection_4 = collection_1;
        CollectionSB collection_5(move(collection_4));
        collection_1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.remove_this_item(stress_ball_2);        
        collection_2.print_items();
        ifstream ifs("stress_ball1.data");
        ifs >> collection_file;
        collection_file.insert_item(stress_ball_3);
        collection_file.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_1);
        
        collection_file.print_items();
        collection_3 = make_union(collection_file,collection_2);
        if(collection_3.total_items() == (collection_file.total_items() + collection_2.total_items())){ 
                          sort_by_size(collection_2,Sort_choice::insertion_sort);                           
                          cout<<collection_3;
        }
}

