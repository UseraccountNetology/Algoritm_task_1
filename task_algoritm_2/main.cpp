
#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int> &massive,int value)
{
    int left = 0;
    int right = static_cast<int>(massive.size()) - 1;
    int firstGreaterPos = static_cast<int>(massive.size()); // по умолчанию все элементы больше (если value очень маленький)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (massive[mid] <= value) {
            // Искомый элемент не подходит (он <= value), ищем правее
            left = mid + 1;
        } else {
            // massive[mid] > value — запоминаем позицию и ищем левее
            firstGreaterPos = mid;
            right = mid - 1;
        }
    }

    // Количество элементов, больших value = massive.size() - firstGreaterPos
    return static_cast<int>(massive.size()) - firstGreaterPos;
}



int main(int argc, char *argv[])
{
    //массив данных
    std::vector<int> massive {14, 16, 19, 32, 32, 32, 56, 69, 72};

    int value=0;

    std::cout<<"Введите точку отсчёта: ";

    //ввод данных
    std::cin>>value;


    //бинарный поиск

    if(BinarySearch(massive,value)!=-1)
    {
        std::cout<<BinarySearch(massive,value)<<std::endl;
    }
    else
    {
        std::cout<<"количество элементов больше:"<<value<<" не найдено"<<std::endl;
    }


}
