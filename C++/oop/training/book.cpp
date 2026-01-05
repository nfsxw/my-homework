class Book {
    public:
        static void setK(float k) {Book::k = k;}
    private:
        float price = 100;
        static float k;
};

float Book::k = 1.0;

int main() {
    Book::setK(1.2);
    Book b1, b2;
    b1.setK(1.0);
}
