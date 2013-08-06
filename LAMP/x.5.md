###apache 绑定多个域名指定不同目录

    NameVirtualHost *:80
    
    <VirtualHost *:80>
            DocumentRoot /web/w1
            ServerName www.w1.com
    </VirtualHost>
    
    <VirtualHost *:80>
            DocumentRoot /web/w2
            ServerName www.w2.com
    </VirtualHost>
