//
// Ask.com programming test 2
//
//    Input a full URL
//    download HTML text of webpage, and include IMG
//
//  using <libcurl>
//
//  This is un-finished program. 
//
//  Wenfeng Wang 06/06/2012
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <pthread.h>
#include <stdio.h>
#include <curl/curl.h>  

string getURLfromString(const string& str){
  // str=<A HREF="http://www.slac.stanford.edu/~wangwf"> 

  //find the starting position of URL
  int iStart=str.find("http");
  if(!iStart) iStart=str.find("HTTP"); 
  if(!iStart) return NULL; 

  //end position of URL
  int iEnd=str.find("\"", iStart); 
  if(iEnd-iStar<0) return NULL; 


  string str_url (str, iStart, iEnd-iStart+1); 
 
  return    str_url ; 
}

// down One image and save into files
void getOneIMG(const string& url_str){

  CURL *curl; 
  CURLcode res;
  curl =curl_easy_init(); 

  int numIMG=0; 
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, url_str); 
    res=curl_easy_perform(curl); 

    //save it into file, don't know how to do it yet?
    //
    curl_easy_cleanup(curl); 
  }

}
// retrieve information from URL
bool downloadURL(const string& url_str){

  CURL *curl; 
  CURLcode res;
  curl =curl_easy_init(); 

  int numIMG=0; 
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, url_str); 
    res=curl_easy_perform(curl); 

    //Analyze for images
    string temp; 
    string* url_str2;
    CURL *curl_t;  
    while(getline(temp, res.readLine())){
      if(temp.find("IMG") || temp.find("img")){
	url_str2[numIMG] = getURLfromString(temp); 
	numIMG++; 
      }
    }

    // multi-thread
    int NumThread=3; 
    pthread_t tid[NumThread]; 
    for(int i=0; i<numIMG; i++){
      int error=pthread_creat(&tid[i],NULL, 
			      getOneIMG, (void*) url_str2[i]);      
    }

    //wait all threads to finish
    for(int i=0; i<NumThread; i++){
      int error=pthread_join(tid[i], NULL); 
    }



    return true; 
  }

  return false; 
}



int main(){


  string testURL="http://www.yahoo.com"; 

  bool isOK=downLoadURL(testURL); 

  cout<<" Does the job finish correctly?  " <<isOK<<endl; 

  return 0; 
}

