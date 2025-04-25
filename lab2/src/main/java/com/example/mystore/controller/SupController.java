package com.example.mystore.controller;

import com.example.mystore.core.Result;
import com.example.mystore.entity.Supplier;
import com.example.mystore.service.SupService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller//要访问到index页就必须使用这个注解(与@GetMapping("/index")配合）而不能用@RestController，否则与GetMapping返回的就是"index"字符而非index页面
public class SupController {
    @Autowired
    private SupService supService;

    @GetMapping("/index")
    public String init(Model model) {
        Result result = new Result();
        result.setCode(100);
        result.setMsg("初始状态");
        model.addAttribute("result", result);
        return "index";
    }

    @RequestMapping("/check")
    public String loginCheck(Model model, Supplier supplier) {
        model.addAttribute("scode", supplier.getScode());
        model.addAttribute("spassword", supplier.getSpassword());
        Result result = supService.checkSupplier(supplier);
        model.addAttribute("result", result);
        if (result.getCode() == 200) {
            Supplier supObj = (Supplier) result.getData();
            model.addAttribute("sname", supObj.getSname());
            model.addAttribute("sweixin", supObj.getSweixin());
            model.addAttribute("tel", supObj.getTel());
            return "home";
        } else return "index";
    }

    @RequestMapping("/login")//运行时访问http://localhost:8080/login?scode=SXLC001A&&spassword=888
    @ResponseBody//默认返回到URL,只有使用这个注解才表示返回JSON
    public Result loginCheck(Supplier supplier) {
        return supService.checkSupplier(supplier);
    }
}
