INSERT INTO radcheck (username,attribute,op,VALUE) VALUES ('用户名','Cleartext-Password',':=','密码');
INSERT INTO radcheck VALUES (NULL ,  '用户名',  'Expiration',  ':=',  '09 Jun 2013 00:01:22');
INSERT INTO radusergroup (username,groupname) VALUES ('用户名','user');
