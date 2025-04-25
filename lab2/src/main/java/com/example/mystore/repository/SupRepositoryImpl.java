package com.example.mystore.repository;

import com.example.mystore.entity.Supplier;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

@Repository
public class SupRepositoryImpl implements SupRepository {
    @Autowired
    private JdbcTemplate jdbcTemplate;//

    @Override
    public Supplier findSupplier(Supplier supplier) {
        try {
            String sql = "SELECT * FROM supplier WHERE SCode = ?"; //sql语句，查询商家记录
            Object args[] = {
                    supplier.getSCode()
            };  //在传入find Supplier()方法的Supplier对象参数中获取商家编码实参值
            RowMapper<Supplier> rowMapper = new BeanPropertyRowMapper<Supplier>(Supplier.class);
            //RowMapper 是 jdbc Template中提供的类，查询数据库得到多列数据
            //映射到一个Supplier上
            Supplier supObj = jdbcTemplate.queryForObject(sql, args, rowMapper);
            //调用jdbc方法做查询，sql语句，实参，数据映射对象
            return supObj;
        } catch (Exception e) {
            return null;
        }
    }
}
