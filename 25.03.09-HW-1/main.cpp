#include<iostream>

class ArrayList
{
private:
	int len;
	int* data;
	void init(int len = 10)
	{
		//(*this).len = len;
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand() {
		int newLen = this->len * 2;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		for (int i = 0; i < this->len; ++i) {
			newData[i] = this->data[i];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
	}

public:
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	ArrayList(ArrayList& list)
	{
		//this->len = list.len;
		//this->data = list.data;
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		//for (int i = 0; i < this->len; ++i)
		//{
		//	this->data[i] = 0;
		//}
		free(this->data);
		//this->data = nullptr;
		//this->len = 0;
	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	void pushBack(int element) {
		if (this->len == this->count()) {
			this->expand();
		}
		this->data[this->len++] = element;
}
	void pushFront(int element) {
		if (this->len == this->count()) {
			this->expand();
		}
		for (int i = this->len; i > 0; --i) {
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = element;
		this->len++;

}
	void insert(int index, int element) {
		if (indexValid(index)) {
			if (this->len == this->count()) {
				this->expand();
			}
			for (int i = this->len; i > index; --i) {
				this->data[i] = this->data[i - 1];
			}
			this->data[index] = element;
			this->len++;
		}
}
	int popBack() {
		if (this->len > 0) {
			int element = this->data[this->len - 1];
			this->len--;
			if (this->len < this->count() / 2) {
				int newLen = this->len;
				int* newData = (int*)malloc(sizeof(int) * newLen);
				for (int i = 0; i < this->len; ++i) {
					newData[i] = this->data[i];
				}
				free(this->data);
				this->data = newData;
				this->len = newLen;
			}
			return element;
		}
		return -1;
	}
	int popFront() {
		if (this->len > 0) {
			int element = this->data[0];
			for (int i = 0; i < this->len - 1; ++i) {
				this->data[i] = this->data[i + 1];
			}
			this->len--;
			return element;
		}
		return -1;
	}
	int extract(int index) {
		if (indexValid(index)) {
			int element = this->data[index];
			for (int i = index; i < this->len - 1; ++i) {
				this->data[i] = this->data[i + 1];
			}
			this->len--;
			return element;
		}
		return -1;
	}
	void reverse(int start, int end) {
		if (start < 0 || end >= this->len || start >= end) {
			return;
		}
		while (start < end) {
			int temp = this->data[start];
			this->data[start] = this->data[end];
			this->data[end] = temp;
			start++;
			end--;
		}

	}
	int sum() {
		int total = 0;
		for (int i = 0; i < this->len; ++i) {
			total += this->data[i];
		}
		return total;
	}

	int secondMax() {
		if (this->len < 2) {
			return -1;
		}
		int first = this->data[0], second = this->data[0];
		for (int i = 1; i < this->len; ++i) {
			if (this->data[i] > first) {
				second = first;
				first = this->data[i];
			} else if (this->data[i] > second && this->data[i] != first) {
				second = this->data[i];
			}
		}
		if (second == first) {
			return -1;
		}
			return second;
	}
	int lastMinIndex() {
		if (this->len == 0) return -1;
		int minIndex = 0;
		for (int i = 1; i < this->len; ++i) {
			if (this->data[i] <= this->data[minIndex]) {
				minIndex = i;
			}
		}
		return minIndex;
	}
	int shift(int k) {
		k = k % this->len;
		if (k < 0) k += this->len;
		this->reverse(0, this->len - 1);
		this->reverse(0, k - 1);
		this->reverse(k, this->len - 1);
		return k;
	}

	int countOdd() {
		int count = 0;
		for (int i = 0; i < this->len; ++i) {
			if (this->data[i] % 2 != 0) {
				count++;
			}
		}
		return count;
	}

	int sumEven() {
		int sum = 0;
		for (int i = 0; i < this->len; ++i) {
			if (this->data[i] % 2 == 0) {
				sum += this->data[i];
			}
		}
		return sum;
	}
};

int max(ArrayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	ArrayList list(10);
	list.randomize();
	list.print();
	printf("%d\n", max(list));
	return 0;
}