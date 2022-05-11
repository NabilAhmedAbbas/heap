#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

template<typename T>
class heapC
{
public:
  T remove_min()
  {
    T temp = heaplist[0];
    heaplist[0] = heaplist[heaplist.size()-1];
    heaplist.pop_back();
    heapify_down(0);
    return temp;
  }

  void insert(T data)
  {
    if (heaplist.size() ==0)
      heaplist.push_back(data);
    else
      {
        heaplist.push_back(data);
        heapify_up(heaplist.size()-1);
      }

  }

  

  void printheap()
  {
    for (auto a: heaplist)
     std::cout<< a<<" ";
    std::cout<<'\n';
  }

private:
  void heapify_down(int pos)
  {
    int index = pos;
    int left = 2*pos +1;
    int right = 2*pos +2;

    if (left < heaplist.size())

        if (heaplist[left] < heaplist[index])
          index = left;

    if (right < heaplist.size())
      if (heaplist[right] < heaplist[index])
          index = right;
    if (index != pos)
      {
        swap(&heaplist[pos], &heaplist[index]);
        heapify_down(index);
      }
  }

  void heapify_up(int pos)
  {
    int parent = floor((pos-1)/2);

    while (heaplist[pos] < heaplist[parent])
       {
         swap(&heaplist[pos], &heaplist[parent]);
         pos = parent;
         parent = floor((pos-1)/2);

       }

  }

 void swap(T *a, T *b)
 {
   T temp = *a;
   *a = *b;
   *b = temp;
 }


  std::vector<T> heaplist;
};


#endif
