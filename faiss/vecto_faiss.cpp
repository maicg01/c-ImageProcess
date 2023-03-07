#include <iostream>
#include <vector>
#include <faiss/IndexFlat.h>
#include <faiss/VectorTransform.h>

using namespace std;

int main() {
  // Tạo ra một vector chứa các giá trị
  vector<float> trainData(512);
  for (int i = 0; i < 512; ++i) {
    trainData[i] = i + 1.0;
  }

  vector<float> trainData1(512);
  for (int i = 0; i < 512; ++i) {
    trainData1[i] = i + 2.0;
  }

  // Chuyển đổi vector thành ma trận và lưu trữ trong đối tượng faiss::IndexFlatL2
  faiss::IndexFlatL2 index(512);
  float* dataPtr = trainData.data();
  float* dataPtr1 = trainData1.data();
  index.add(1, dataPtr);
  index.add(1, dataPtr1);

  // Tìm kiếm vector gần nhất
  vector<float> query(512);
  for (int i = 0; i < 512; ++i) {
    query[i] = i + 2.0;
  }
  float* queryPtr = query.data();
  float* distances = new float[1];
  int64_t* labels = new int64_t[1];
  index.search(1, queryPtr, 2, distances, labels); //so thu 2 la so luong vecto tuong tu tra ve, so dau tien la so luong vecto can tim kiem

  // In ra kết quả
  cout << "Distances: " << endl;
  cout << *distances << endl;

  cout << "Labels: " << endl;
  cout << *(labels+1) << endl;

  // Giải phóng bộ nhớ đã được cấp phát
  delete[] distances;
  delete[] labels;

  return 0;
}