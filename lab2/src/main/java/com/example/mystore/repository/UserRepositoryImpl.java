package com.example.mystore.repository;

import com.example.mystore.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.EnableAspectJAutoProxy;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

@Repository
public class UserRepositoryImpl implements UserRepository {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public User findUser(User user) {
        try {
            String sql = "SELECT * FROM user WHERE UCode = ?";
            Object args[] = {
                user.getUcode()
        };
        RowMapper<User> rowMapper = new BeanPropertyRowMapper<User>(User.class);
        User userObj = jdbcTemplate.queryForObject(sql, args, rowMapper);
        return userObj;
        }catch (Exception e0){
            return null;
        }
    }
}
