#pragma once
#include <iostream>


using namespace std;




template <class T>
class Range;

template <class T>
ostream& operator <<(ostream&, const Range<T>&);


template <class T>
class Range {
	private:
		T start;
		T end;
		T step;
	
	public:
		Range(T start, T end) : start(start), end(end), step(1) {}
		Range(T start, T end, T step) : start(start), end(end), step(step) {}
		Range noStep(Range<T>&);
		Range yesStep(Range<T>&);
		int length();
		T sum();
		T average();
		T max();
		T min();
		friend ostream& operator<<(ostream&, const Range<T>&);
};


template <class T>
Range<T> Range<T>::noStep(Range<T>& r) {
	for (T i = r.start; i <= r.end; i++) {
		cout << i << " " << endl;
	}
	cout << endl;
	
}

template <class T>
Range<T> Range <T>::yesStep(Range<T>& r) {
	for (T i = r.start; i <= r.end; i += r.step) {
		cout << i << " " << endl;
	}
	cout << endl;
	
}


int Range<int>::length() {
	int length = ((end - start) + step - 1) / step;
	return length;
}

template <class T>
T Range <T>::sum() {
	T sum = 0;
	for (T i = start; i < end; i += step) {
		sum += i;
	}
	return sum;

}

template <class T>
T Range<T>::average() {
	T len = length();
	T total = sum();
	int average = total/ len;
	return average;
}

template <class T>
T Range <T>::min() {
	T min;
	if (start > end) {
		min = end;
	}
	else if (end > start) {
		min = start;
	}
	return min;
}

template <class T>
T Range<T>::max() {
	T max;
	if (start > end) {
		max = start;
	}
	if (end > start) {
		max = end;
	}
	return max;
}

template <class T>
ostream& operator<<(ostream& out, const Range<T>& r) {
	for (T i = r.start; i <= r.end; i += r.step) {
		if (i != r.start) {
			out << ", ";
		}
		out << i;
	}
	out << endl;
	return out;
}
