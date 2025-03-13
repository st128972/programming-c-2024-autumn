#include<iostream>

class ArrayList {
private:
	int len;
	int* data;
	void init(int len = 10)
	{
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index && index < this->len;
	}
	void expand() {
		int newlen = this->len * 2;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata == nullptr) {
			return;
		}
		for (int i = 0; i < this->len; ++i) {
			newdata[i] = this->data[i];
		}
		free(this->data);
		this->data = newdata;
		this->len = newlen;
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
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);
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
		int* newdata = (int*) malloc(sizeof(int) * (this->len + 1));
		if (newdata == nullptr)
		{
			return;
		}
		for (int i = 0; i < this->len; ++i)
		{
			newdata[i] = this->data[i];
		}
		newdata[this->len] = element;
		++this->len;
		free(this->data);
		this->data = newdata;
	}
	void pushFront(int element) {
		int* newdata = (int*) malloc(sizeof(int) * (this->len + 1));
		if (newdata == nullptr)
		{
			return;
		}
		for (int i = 0; i < this->len; ++i)
		{
			newdata[i + 1] = this->data[i];
		}
		newdata[0] = element;
		++this->len;
		free(this->data);
		this->data = newdata;
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
			++this->len;
		}
	}
	int popBack() {
		if (this->len == 0) {
			return -1;
		}
		int element = this->data[this->len - 1];
		--this->len;
		int newlen = this->len;
		if (newlen > 0) {
			int* newdata = (int*)malloc(sizeof(int) * newlen);
			if (newdata == nullptr) {
				return element;
			}
			for (int i = 0; i < newlen; ++i) {
				newdata[i] = this->data[i];
			}
			free(this->data);
			this->data = newdata;
		} else {
			free(this->data);
			this->data = nullptr;
		}
		return element;
	}
	int popFront() {
		if (this->len > 0) {
			int element = this->data[0];
			for (int i = 0; i < this->len - 1; ++i) {
				this->data[i] = this->data[i + 1];
			}
			--this->len;
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
			--this->len;
			return element;
		}
		return -1;
	}
	void reverse(int start, int end) {
		if (start < 0 || end >= this->len || start >= end) {
			return;
		}
		while (start < end) {
			int t = this->data[start];
			this->data[start] = this->data[end];
			this->data[end] = t;
			++start;
			--end;
		}
	}
	int sum() {
		int r = 0;
		for (int i = 0; i < this->len; ++i) {
			r += this->data[i];
		}
		return r;
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
		if (this->len == 0) {
			return -1;
		}
		int minInd = 0;
		for (int i = 1; i < this->len; ++i) {
			if (this->data[i] <= this->data[minInd]) {
				minInd = i;
			}
		}
		return minInd;
	}
	int shift(int k) {
		if (this->len ==0 || k % this->len == 0) {
			return -1;
		}
		k = (k % this->len + this->len) % this->len;
		int* newdata = (int*) malloc(sizeof(int) * this->len);
		if (newdata == nullptr)
		{
			return -1;
		}
		for (int i = 0; i < k; ++i)
		{
			newdata[i] = this->data[this->len - k + i];
		}
		for (int i = k; i < this->len; ++i)
		{
			newdata[i] = this->data[i - k];
		}
		free(this->data);
		this->data = newdata;
		return 0;
	}
	int countOdd() {
		int count = 0;
		for (int i = 0; i < this->len; ++i) {
			if (this->data[i] % 2 != 0) {
				++count;
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

int main(int argc, char* argv[]) {
	ArrayList list(10);
	list.randomize();
	list.print();
	printf("%d\n", max(list));
	return 0;
}