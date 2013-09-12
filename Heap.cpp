#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

// heap操作
// heap[0] はダミー
typedef vector<int> Heap;

int parent(int i) { return i/2; }
int left(int i) { return 2*i; }
int right(int i) { return 2*i+1; }

// i を根とする部分木が max-heap になるように heap[i] を滑り落とす
void maxHeapify(Heap &heap, const int i, const int heapSize)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l<heapSize && heap[l]>heap[largest]) largest = l;
	if (r<heapSize && heap[r]>heap[largest]) largest = r;

	if (largest != i) {
		swap(heap[i], heap[largest]);
		maxHeapify(heap, largest, heapSize);
	}
}

// maxHeapfy の逆
void minHeapify(Heap &heap, const int i, const int heapSize)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l<heapSize && heap[l]<heap[smallest]) smallest = l;
	if (r<heapSize && heap[r]<heap[smallest]) smallest = r;

	if (smallest != i) {
		swap(heap[i], heap[smallest]);
		minHeapify(heap, smallest, heapSize);
	}
}

// heap を max-heap にする
void buildMaxHeap(Heap &heap)
{
	for (int i=heap.size()/2; 0 < i; --i) {
		maxHeapify(heap, i, heap.size());
	}
}

// heap を min-heap にする
void buildMinHeap(Heap &heap)
{
	for (int i=heap.size()/2; 0 < i; --i) {
		minHeapify(heap, i, heap.size());
	}
}

// heap をソート
void heapSort(Heap &heap)
{
	buildMaxHeap(heap);
	//buildMinHeap(heap);

	int heapSize = heap.size();
	for (int i=heap.size()-1; 1 < i; --i) {
		swap(heap[1], heap[i]);
		maxHeapify(heap, 1, --heapSize);
		//minHeapify(heap, 1, --heapSize);
	}
}

// heap の最大の値をとりだす
int heapExtractMax(Heap &heap, int heapSize)
{
	if (heapSize < 1) assert(!"Heap Under Flow");
	int maxValue = heap[1];
	heap[1] = heap[heapSize];
	--heapSize;
	maxHeapify(heap, 1, heapSize);
	return maxValue;
}

// max-heap を保ちながら節点の値を上昇させる
void heapIncreaseKey(Heap &heap, int i, const int key)
{
	if (key < heap[i]) assert(!"newKey < nowKey");
	heap[i] = key;
	while (i>1 && heap[parent(i)] < heap[i]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

// max-heap を保ちながら節点を追加する
void maxHeapInsert(Heap &heap, const int key)
{
	heap.push_back(INT_MIN);
	heapIncreaseKey(heap, heap.size()-1, key);
}

