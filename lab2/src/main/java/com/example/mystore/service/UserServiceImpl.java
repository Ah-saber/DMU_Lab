package com.example.mystore.service;

import com.example.mystore.core.Result;
import com.example.mystore.entity.User;
import com.example.mystore.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService{
    @Autowired
    private UserRepository userRepository;

    @Override
    public Result checkUser(User user){
        User useObj = userRepository.findUser(user);
        Result result = new Result();
        result.setRole("顾客");
        if (useObj == null) {
            result.setCode(404);
            result.setMsg("用户不存在！");
        } else {
            if (!user.getUpassword().equals(useObj.getUpassword())) {
                result.setCode(403);
                result.setMsg("密码错！");
            } else {
                result.setCode(200);
                result.setMsg("验证通过");
                result.setData(useObj);
            }
        }
        return result;
    }
}
