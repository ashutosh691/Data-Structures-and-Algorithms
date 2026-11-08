class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool z = true, o = false, e = false;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return z; });

            printNumber(0);

            z = false;

            if (i % 2 == 1)
                o = true;
            else
                e = true;

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return e; });

            printNumber(i);

            e = false;
            z = true;

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [&]() { return o; });

            printNumber(i);

            o = false;
            z = true;

            cv.notify_all();
        }
    }
};