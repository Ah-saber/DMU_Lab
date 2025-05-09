package com.example.mystore.controller;

import com.example.mystore.core.Result;
import com.example.mystore.entity.Supplier;
import com.example.mystore.entity.User;
import com.example.mystore.service.SupService;
import com.example.mystore.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.env.Environment;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
public class LogController {
    @Autowired
    private Environment environment;
    @Autowired
    private SupService supService;
    @Autowired
    private UserService userService;
    //当前环境配置
    @Value("${spring.profiles.active}")
    private String active;
    //用户名
    private String code;
    //密码
    private String password;
    //响应结果
    private Result result;

    @GetMapping("/index")   //处理对index的get请求
    public String init(Model model) {
        result = new Result();
        result.setCode(100);
        result.setMsg("初始状态");
        //根据当前环境配置确定以何种身份(商家、顾客)登录系统(从配置文件读取的用户信息自动填写在前端页面上)
        if (active.equals("sup")) {
            code = environment.getProperty("supplier.scode");
            password = environment.getProperty("supplier.spassword");
            result.setRole("商家");
        } else if (active.equals("user")) {
            code = environment.getProperty("user.ucode");
            password = environment.getProperty("user.upassword");
            result.setRole("顾客");
        } else {
            code = "";
            password = "";
            result.setRole("默认");
        }
        model.addAttribute("code", code);
        model.addAttribute("password", password);
        model.addAttribute("result", result);
        return "index";
    }

    @RequestMapping("/check")
    public String loginCheck(Model model, Supplier supplier, User user) {
        if (active.equals("sup")) {
            model.addAttribute("code", supplier.getScode());
            model.addAttribute("password", supplier.getSpassword());
            result = supService.checkSupplier(supplier);
        } else if (active.equals("user")) {
            model.addAttribute("code", user.getUcode());
            model.addAttribute("password", user.getUpassword());
            result = userService.checkUser(user);
        }
        model.addAttribute("result", result);
        if (result.getCode() == 200) {   //200代表验证成功
            if (active.equals("sup")) {
                Supplier supObj = (Supplier) result.getData();
                model.addAttribute("name", supObj.getSname());
            } else if (active.equals("user")) {
                User useObj = (User) result.getData();
                model.addAttribute("name", useObj.getUname());
            }
            return "home";
        } else return "index";  //跳转到哪个页面
    }
}
