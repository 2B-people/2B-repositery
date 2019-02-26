#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <stdio.h>

using namespace std;


enum class DictionaryType
{
    NONE,
    BOOL,       //布尔
    COORDINATE, //坐标
};

//字典基类,提供接口
class DirBase : public std::enable_shared_from_this<DirBase>
{
  public:
    typedef std::shared_ptr<DirBase> Ptr;
    DirBase(DictionaryType dictionary_type)
        : dictionary_type_(dictionary_type){}, , flag_(true){};
    virtual ~DirBase() = default;
    //得到字典类型
    DictionaryType GetDictionaryType()
    {
        return dictionary_type_;
    }

  protected:
    virtual void OnInit() = 0;

    void Lock()
    {
        flag_ = false;
    }
    void OpenLock()
    {
        flag_ = true;
    }
    bool flag_;
  private:
    DictionaryType dictionary_type_;
    //data
};

//布尔类型
class BoolDir : public DirBase
{
  public:
    BoolDir(bool initial_data)
        : DirBase::DirBase(DictionaryType::BOOL), initial_data_(initial_data);
    {
        middle_data_ = initial_data_;
        real_data_ = middle_data_;
    };
    virtual ~BoolDir() = default;
    bool GetValue()
    {
        return real_data_;
    }

  protected:
    void Set(bool set_data)
    {
        middle_data_ = set_data;
        if (flag_)
        {
            real_data_ = middle_data_;
        }
        else
        {
            printf("%s is lock");
        }
    }

    void OnInit()
    {
        flag_ = true;
        middle_data_ = initial_data_;
        real_data_ = initial_data_;
    }

  private:
    bool middle_data_;
    bool initial_data_;
    bool real_data_;
};

//坐标类型
class CoordinateDir : public DirBase
{
  public:
    CoordinateDir(uint16_t initial_x, uint16_t initial_y)
        : DirBase::DirBase(DictionaryType::COORDINATE), initial_x_(initial_x), initial_y_(initial_y)
    {
        x_middle_data_ = initial_x_;
        y_middle_data_ = initial_y_;
        x_real_data_ = x_middle_data_;
        y_real_data_ = y_middle_data_;
    };
    virtual ~CoordinateDir() = default;
    uint16_t GetCoordinateX()
    {
        return x_real_data_;
    }
    uint16_t GetCoordinateY()
    {
        return y_real_data_;
    }

  protected:
    void Set(uint16_t set_x, uint16_t set_y)
    {
        x_middle_data_ = set_x;
        y_middle_data_ = set_y;
        if (flag_)
        {
            x_real_data_ = x_middle_data_;
            y_real_data_ = y_middle_data_;
        }
        else
        {
            printf("%s is lock", name_);
        }
    }
    void OnInit()
    {
        x_middle_data_ = initial_x_;
        y_middle_data_ = initial_y_;
        x_real_data_ = initial_x_;
        y_real_data_ = initial_y_;
    }

  private:
    uint16_t initial_x_;
    uint16_t initial_y_;
    uint16_t x_middle_data_;
    uint16_t y_middle_data_;
    uint16_t x_real_data_;
    uint16_t y_real_data_;
};

// class PosaDir:public
// {
// private:
//     /* data */
// public:
//     PosaDir(/* args */);
//     ~PosaDir();
// };

//黑板基类
class Blackboard : public std::enable_shared_from_this<Blackboard>
{

  public:
    typedef std::shared_ptr<Blackboard> Ptr;
    Blackboard(){};
    virtual ~Blackboard() = default;
    unsigned int GetWorldDataSize()
    {
        return world_data_map_.size();
    }
    // @breif 添加字典到world_data
    void AddDataIntoWorld(std::string key, DirBase::Ptr dir_ptr)
    {
        if (world_data_map_.size())
        {
            world_data_map_.insert(std::pair<std::string, DirBase::Ptr>(key, dir_ptr));
        }
        else
        {
            auto search = world_data_map_.find(key);
            if (search != world_data_map_.end())
            {
                ROS_INFO("AddData is WARN:key: %s is in dirctionaries!!", key.c_str());
            }
            else
            {
                world_data_map_.insert(std::pair<std::string, DirBase::Ptr>(key, dir_ptr));
            }
        }
    }
    // @breif 清除world_data的所有数据,慎用
    void ClearWorldDataALL()
    {
        ROS_INFO("blackboard is cleared!");
        world_data_map_.clear();
    }
    // @breif 取得目标数据字典类的指针
    //       -注意:此方法传回来只能是基类指针,必须使用std::dynamic_pointer_cast<Temp>来转化类型
    // @param key:目标数据的key
    // @return 字典基类的指针
    DirBase::Ptr GetDirPtr(std::string key)
    {
        if (world_data_map_.size() == 0)
        {
            ROS_WARN("dirctionary is nothings!");
            return nullptr;
        }
        auto search = world_data_map_.find(key);
        if (search != world_data_map_.end())
        {
            return world_data_map_[key];
        }
        else
        {
            ROS_WARN("Can't find key:%s in dirctionary", key);
            return nullptr;
        }
    }
    //example:
    // bool GetBoolValue(std::string key)
    // {
    //     auto dir_ptr = GetDirPtr(key);
    //     auto bool_dir_ptr = std::dynamic_pointer_cast<BoolDir>(dir_ptr);
    //     return bool_dir_ptr->GetValue();
    // }

  protected:
  private:
    //数据结构:map容器,储存字典指针
    std::map<std::string, DirBase::Ptr> world_data_map_;
};


int main()
{
    map<string,DirBase::Ptr> test;
    test["1"] = make_shared<BoolDir>(true);
    test["2"] = make_shared<CoordinateDir>(10,2);
    test["3"] = make_shared<BoolDir>(false);

    auto aaaa = test.find("4");
    if(aaaa == test.end()){
    cout<<"waring"<<endl;
    }
}