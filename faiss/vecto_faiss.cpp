#include <iostream>
#include <vector>
#include <fstream>
#include <faiss/IndexFlat.h>
#include <faiss/IndexIVF.h>
#include <faiss/index_io.h>
#include <faiss/VectorTransform.h>

using namespace std;

void saveIndex(faiss::IndexFlatL2* index, const char* filename) {
  // Mở file để ghi dữ liệu
  FILE* file = fopen(filename, "wb");

  // Lưu trữ đối tượng IndexFlat vào file
  faiss::write_index(index, file);

  // Đóng file
  fclose(file);
}


faiss::IndexFlatL2* loadIndex(const char* filename) {
  // Mở file để đọc dữ liệu
  FILE* file = fopen(filename, "rb");

  // Tải đối tượng Index vào bộ nhớ
  faiss::IndexFlatL2* index = dynamic_cast<faiss::IndexFlatL2*>(faiss::read_index(file));

  // Đóng file
  fclose(file);

  return index;
}

void searchIndex(faiss::IndexFlat* index, float* query, int nq, int k, float* distances, int64_t* labels) {
  // Tìm kiếm các vector gần nhất
  index->search(nq, query, k, distances, labels);
}

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

  saveIndex(&index,"meme.bin");

  // Giải phóng bộ nhớ đã được cấp phát
  delete[] distances;
  delete[] labels;

  faiss::IndexFlatL2* index2;
  index2 = loadIndex("/home/maicg/Documents/cplus/faiss/build/meme.bin");
  float* distances2 = new float[1];
  int64_t* labels2 = new int64_t[1];
  searchIndex(index2, query.data(),1,2,distances2,labels2);

  cout << "Labels22: " << endl;
  cout << *(labels2) << endl;

  // Giải phóng bộ nhớ đã được cấp phát
  delete[] distances2;
  delete[] labels2;


  return 0;
}