#include "arack_one.h"
#include <QDateTime>
arack_one::arack_one(QString name,QObject *parent)
:arack_base(name,ft_rack_type,parent)
{
    //初始化矩阵
    for(int i=0;i<m_row_num;i++)
    {
        QVector<rack_pos*> tmp_matrix_row;
        for(int j=0;j<m_col_num;j++)
        {
            rack_pos *tmp_pos = new rack_pos();
            tmp_matrix_row.append(tmp_pos);
        }
        m_pos_matrix.append(tmp_matrix_row);
    }
}

uint8_t arack_one::row_num()
{
    return m_row_num;
}

uint8_t arack_one::col_num()
{
    return m_col_num;
}

void arack_one::bind_mi_pv(uint8_t row, uint8_t col, QString mi_cid, uint8_t pv)
{
    if(!is_row_col_valid(row,col))
        return;

    m_pos_matrix[row-1][col-1]->bind_mi_pv(mi_cid,pv);
}

void arack_one::unbind_mi_pv(uint8_t row, uint8_t col)
{
    if(!is_row_col_valid(row,col))
        return;
    m_pos_matrix[row-1][col-1]->unbind_mi_pv();
}

void arack_one::unbind_all_mi_pv()
{
    for(int i=0;i<m_row_num;i++)
    {
        for(int j=0;j<m_col_num;j++)
        {
            unbind_mi_pv(i+1,j+1);
        }
    }
}

void arack_one::update_pos_data(uint8_t row, uint8_t col, rack_mi_data pos_data)
{
    if(!is_row_col_valid(row,col))
        return;

    m_pos_matrix[row-1][col-1]->update_pos_data(pos_data);
}

void arack_one::get_pos_dev(uint8_t row, uint8_t col, QVector<mi_pv_map_struc> &mi_pv_map)
{
    if(!is_row_col_valid(row,col))
        return;
    mi_pv_map = m_pos_matrix[row-1][col-1]->get_mi_cid_map();
}

void arack_one::get_pos_rack_data(uint8_t row, uint8_t col, rack_mi_data &data)
{
    if(!is_row_col_valid(row,col))
        return;
    data = m_pos_matrix[row-1][col-1]->get_cur_data();
}

rack_pos *arack_one::get_pos_obj(uint8_t row, uint8_t col)
{
    if(!is_row_col_valid(row,col))
        return nullptr;
    return m_pos_matrix[row-1][col-1];
}

bool arack_one::is_row_col_valid(uint8_t row, uint8_t col)
{
    if(row > m_row_num || row <=0 || col >m_col_num || col <= 0)
        return false;

    return true;
}


/*    rack_pos     */


void rack_pos::bind_mi_pv(QString mi_cid, uint8_t pv)
{
    bool b_mi_exist_flag = false,b_pv_exist_flag = false;
    int i = 0;
    //遍历当前节点绑定微逆
    for(i=0;i<m_mi_pv_map.size();i++)
    {
        b_mi_exist_flag = false;
        //找到一样的微逆
        if(m_mi_pv_map[i].mi_cid == mi_cid)
        {
            b_mi_exist_flag = true;
            //找到该微逆的pv路
            if(m_mi_pv_map[i].pv_list.contains(pv))
            {
                b_pv_exist_flag = true;
                break;
            }
        }
    }
    //如果微逆已经存在
    if(b_mi_exist_flag)
    {
        //如果pv不存在 则更新 pv
        if(!b_pv_exist_flag)
        {
            m_mi_pv_map[i].pv_list.append(pv);
        }
    }
    else
    {
        mi_pv_map_struc tmp_mi_pv_map;
        tmp_mi_pv_map.mi_cid = mi_cid;
        tmp_mi_pv_map.pv_list.append(pv);
        m_mi_pv_map.append(tmp_mi_pv_map);
    }
}

void rack_pos::unbind_mi_pv()
{
    rack_mi_data tmp_empty = {};

    m_pos_cur_data = tmp_empty;
    m_mi_pv_map.clear();
}

void rack_pos::update_pos_data(rack_mi_data pos_data)
{
    m_pos_cur_data = pos_data;
}

QVector<mi_pv_map_struc> rack_pos::get_mi_cid_map()
{
    return m_mi_pv_map;
}

rack_mi_data rack_pos::get_cur_data()
{
    return m_pos_cur_data;
}

void rack_pos::analysis_row_col(QString pos, uint8_t &row, uint8_t &col)
{
    int tmp_index = pos.indexOf("-");
    if(tmp_index == -1)
        return;
    row = pos.mid(0,tmp_index).toUInt();
    col = pos.mid(tmp_index+1).toUInt();
}




