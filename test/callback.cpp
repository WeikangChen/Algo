#include <iostream>
#include <vector>
#include <ctime>
#include <cstdint>
using namespace std;

static void on_soup_data(const unsigned char *data, void *aux)
{
    cout << __FUNCTION__ << endl;
}

static void on_soup_ready(void *aux)
{
    cout << __FUNCTION__ << endl;
}

static void on_soup_eof(void *aux)
{
    cout << __FUNCTION__ << endl;
}

static void on_soup_error(void *aux)
{
    auto* p = static_cast<char*>(aux);
    cout << "error: " << p << endl;
}


struct soup_ops {
    void (*on_data)(const unsigned char *data, void *aux);
    void (*on_ready)(void *aux);
    void (*on_eof)(void *aux);
    void (*on_error)(void *aux);
};

static const soup_ops itto_soup_ops = {
    .on_data  = &on_soup_data,
    .on_ready = &on_soup_ready,
    .on_eof   = &on_soup_eof,
    .on_error = &on_soup_error
};


class soup_session
{
    typedef function<void(const int n)> AnnFunc;

  public:
    bool has_rdm_client = true;
    soup_session() {}
    const struct soup_ops *soup_ops_;
    void init(const struct soup_ops *ops);
    void on_ready() {soup_ops_->on_ready(nullptr);}
    void on_deactivated() {soup_ops_->on_eof(nullptr);}
    void on_error(const char* p) {soup_ops_->on_error((void*)p);}
    AnnFunc ann_func;
    void set_ann_func(AnnFunc f) {ann_func = f;};
};

void soup_session::init(const struct soup_ops *ops)
{
    soup_ops_ = ops;
    set_ann_func(
        [this](const int n) {
            cout << "ann_func:" << n << endl;
            on_ready();
            if(has_rdm_client)
                on_error("has_rdm_client=true");
            else
                on_error("has_rdm_client=false");
        }
    );
}

int main()
{
    soup_session soup_sess;
    soup_sess.init(&itto_soup_ops);
    soup_sess.on_ready();
    soup_sess.on_error("abc");
    soup_sess.ann_func(3);
    soup_sess.has_rdm_client = false;
    soup_sess.ann_func(3);
}

/*
int main(int argc, char ** argv)
{
    static soup_ops itto_soup_ops;
    itto_soup_ops.on_data  = &on_soup_data;
    itto_soup_ops.on_ready = &on_soup_ready;
    itto_soup_ops.on_eof   = &on_soup_eof;
    itto_soup_ops.on_error = &on_soup_error;

    return 0;
}
*/
