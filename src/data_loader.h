#pragma once
#include <string>
class DataLoader
{

public:
    DataLoader(const std::string &image_path, const std::string &label_path);
    ~DataLoader();

    // 获取一批数据 image_batch_size = batch_size * rows * cols
    bool next_batch(int batch_size, float *image_batch, int *label_batch);
    //返回图片数量
    int total_samples() const {return num_images;}

    int image_rows() const {return rows;}

    int image_cols() const {return cols;}

    //重置索引至初始位置
    void reset(){current_index =0;}

    //支持从任意索引开始重置
    void reset(int start_index);

    //移动读取位置
    void seek(int index);
private:
    bool load_images(const std::string& filepath);

    bool load_labels(const std::string& filepath);

    int reverse_int(int i);

private:
    float* images;
    int* labels;
    int num_images;
    int rows;
    int cols;
    int current_index;
};