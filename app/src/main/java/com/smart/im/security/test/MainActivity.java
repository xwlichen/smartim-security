package com.smart.im.security.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.smart.im.security.utils.EncryptionUtil;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String md5= EncryptionUtil.md5("sdfs");
        TextView textView=findViewById(R.id.tvMd5);
        textView.setText(md5);
    }
}
