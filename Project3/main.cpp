
#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "movies.h"


int main() {
    vector<Movies> moviesV;
    readMoviesFromFile("../Films.csv", moviesV);
    cout<< moviesV.size()<< endl;
    //Create Binary Search tree of Movie Objects
    BinarySearchTree<Movies> BinarySearch;
    //Creat AVL search tree of movie objects
    AVLTree<Movies> AVLsearch;
    //Create a splay tree of movie objects
    SplayTree<Movies> SplaySearchTree;



    //Loop through movies vector to add values to binarySearch Tree
    for(int x = 0; x<1021; x++){
        BinarySearch.add(moviesV[x]);
    }


    //Loop through movies vector to add values to AVL Tree
    for(int y = 0; y<1021; y++){
        AVLsearch.add(moviesV[y]);
    }


    //Loop through movies vector to add values to SplayTree
    for(int a = 0; a<1021; a++){
        SplaySearchTree.add(moviesV[a]);
    }



    //Test to make sure all the trees are filled
    //for (int z = 0; z<1021; z++){
        //cout<< moviesV[z]<< endl;
//}


    //Tests
    //Create dummy movie objects that are not in trees
    Movies movieD;
    Movies movieD1;
    Movies movieD2;
    int dummyDepth = 0;
    int dummyDepth1 = 0;
    int dummyDepth2 = 0;

    cout << BinarySearch.find(movieD, dummyDepth) << endl;
    cout << dummyDepth << endl ;
    cout<< AVLsearch.find(movieD1, dummyDepth1 ) << endl;
    cout << dummyDepth1 << endl;
    cout<< SplaySearchTree.find(movieD2, dummyDepth2) << endl;
    cout<<dummyDepth2<<endl;

    //Read integers from file
    int n = 0;

    //Create depths
    int BinarySearchSortedDepth = 0;
    int BinarySearchRandomDepth = 0;
    int BinarySearch5Depth = 0;
    int AVLSearchSortedDepth = 0;
    int AVLSearchRandomDepth = 0;
    int AVLSearch5Depth = 0;
    int SplaySearchSortedDepth = 0;
    int SplaySearchRandomDepth = 0;
    int SplaySearch5Depth = 0;

    //Create file to read from
    ifstream sortedNum("../sortedNum.txt");
    //Create file to write to
    ofstream BSTsortedNum("../BSTSortedNumDepths.txt");
    ofstream AVLsortedNum("../AVLSortedNumDepths.txt");
    ofstream SplaysortedNum("../SplaySortedNumDepths.txt");


    //Create loop to step through sortedNum
    while (sortedNum && sortedNum.peek() != EOF) {
        sortedNum >> n;
        //Look for movie object at index n whithin the binary search tree
        BinarySearch.find(moviesV[n], BinarySearchSortedDepth);
        BSTsortedNum << BinarySearchSortedDepth << endl;
        //Look for movie object at index n within AVL tree and write them to sortedAVLFile
        AVLsearch.find(moviesV[n],AVLSearchSortedDepth);
        AVLsortedNum << AVLSearchSortedDepth << endl;
        //Look for movie object at index n within AVL tree and write them to sortedSplay File
        SplaySearchTree.find(moviesV[n], SplaySearchSortedDepth);
        SplaysortedNum << SplaySearchSortedDepth << endl;


    }


    //Create file to read from randomNum
    ifstream randomNum("../randomNum.txt");
    //Create file to write to Random depths
    ofstream BSTrandomNum("../BSTRandomNumDepths.txt");
    ofstream AVLrandomNum("../AVLRandomNumDepths.txt");
    ofstream SplayrandomNum("../SplayRandomNumDepths.txt");



    //Create loop to step through randomNum
    while (randomNum && randomNum.peek() != EOF) {
        randomNum >> n;
        //Look for movie object at index n whithin the binary search tree
        BinarySearch.find(moviesV[n], BinarySearchRandomDepth);
        BSTrandomNum << BinarySearchRandomDepth << endl;
        //Look for movie object at index n within AVL tree and write them to sortedAVLFile
        AVLsearch.find(moviesV[n],AVLSearchRandomDepth);
        AVLrandomNum << AVLSearchRandomDepth << endl;
        //Look for movie object at index n within AVL tree and write them to sortedSplay File
        SplaySearchTree.find(moviesV[n], SplaySearchRandomDepth);
        SplayrandomNum << SplaySearchRandomDepth << endl;


    }


    //Create file to read from div5
    ifstream div5Num("../NumDiv5.txt");
    //Create file to write to div 5 depths
    ofstream BSTdiv5Num("../BSTdiv5Depths.txt");
    ofstream AVLdiv5Num("../AVLdiv5Depths.txt");
    ofstream Splaydiv5Num("../Splaydiv5Depths.txt");

    //Create loop to step through div5Num
    while (div5Num && div5Num.peek() != EOF) {
        div5Num >> n;
        //Look for movie object at index n whithin the binary search tree
        BinarySearch.find(moviesV[n], BinarySearch5Depth);
        BSTdiv5Num << BinarySearch5Depth << endl;
        //Look for movie object at index n within AVL tree and write them to sortedAVLFile
        AVLsearch.find(moviesV[n],AVLSearch5Depth);
        AVLdiv5Num << AVLSearch5Depth << endl;
        //
        SplaySearchTree.find(moviesV[n], SplaySearch5Depth);
        Splaydiv5Num << SplaySearch5Depth << endl;


    }














}