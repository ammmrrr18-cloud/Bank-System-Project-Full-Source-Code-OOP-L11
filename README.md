# <p align="center"> **💎 Integrated Bank Management System - Level 11 💎** </p>

**This repository contains the complete source code and final version of the Bank Management System. This project serves as an advanced practical application, where I transformed all Object-Oriented Programming (OOP) concepts studied "theoretically" in [Level 10](https://github.com/ammmrrr18-cloud/Programming-Foundations-Roadmap/tree/main/10-OOP-as-it-Should-Be-Concepts) into a high-performance, real-world functional system.**

---

### **💡 Project Build Journey (Step-by-Step Evolution):**
**This system was not built all at once; it is the result of a meticulous step-by-step learning and implementation process. You can view the evolution stages, programming exercises, and mini-systems that preceded this final project through the following link:**
[**📂 Level 11 Application Build Stages (Lesson Progression)**](https://github.com/ammmrrr18-cloud/Programming-Foundations-Roadmap/tree/main/11-OOP-as-it-Should-Be-Applications)
**There, you will find the repository organized into independent folders, each representing a specific lesson or stage in the course with its own files, demonstrating the logical sequence of building complex systems.**

---

## **🔵 Detailed Project Systems**
**The system is designed to be a realistic simulation of a professional banking environment, divided into integrated sub-systems to ensure efficiency and ease of use:**

### **🔴 1. Client Management & Transactions System**
**The core heart of the bank, merging depositor record management with high-precision financial operations:**
* **👤 Account Management:** Provides full control over the client's "lifecycle" (Add, Edit, Search, Delete).
* **💸 Transactions Menu:** A built-in sub-system dedicated to fund management, including:
    * **📥 Deposit & Withdraw:** Interactive screens to execute operations with real-time balance updates.
    * **🔄 Money Transfer:** Advanced feature for instant balance transfer between two accounts.
    * **📊 Total Balances Report:** A dedicated screen providing a comprehensive report summarizing all client balances.

### **🟢 2. User Management & Permissions System**
**Designed for security, allowing multiple administrative roles within the bank:**
* **🔑 Secure Access Portal:** A smart login screen that protects bank data and verifies every user (employee) before granting access.
* **🛡️ Permissions Framework:** A professional system that assigns specific permissions to each employee based on their role.
* **👥 Staff Management:** A control panel to add, block, or update users and review their permissions.

### **🟡 3. Currency Exchange Suite**
**An integrated sub-system for managing international currencies and linking them to the USD in real-time:**
* **🌍 Currency Center:** A database containing global currencies registered in the system with their exchange rates.
* **💹 Rate Update & Calculator:** Manual exchange rate updates with a smart tool for quick conversion between any two currencies.

### **🟠 4. Logging & Monitoring System**
**Ensures the highest level of oversight and transparency by documenting every activity:**
* **📝 Login Register:** Precise tracking of every login attempt (Username, Date, Time) to prevent unauthorized access.
* **📜 Transfer Log:** Historical documentation of every financial transfer, showing parties involved, amounts, time, and the responsible user.

---

## **🔒 Data Protection & Encryption**
**The system is fortified with an additional layer of security to ensure the confidentiality of sensitive data:**
* **🛡️ Password Encryption:** Client and user passwords are never stored in plain text; they are encrypted using a custom algorithm before saving.
* **💾 File Security:** Data in `Clients.txt` and `Users.txt` appears scrambled and unreadable from outside the program, protecting privacy.
* **⚙️ String Processing Engine:** The system relies on the **`clsString`** class, which includes encryption/decryption functions processed instantly during Read/Write operations.

---

## **🛠️ Repository Contents**
**This folder contains everything you need to run the project immediately:**
1.  **📄 Header Files (.h):** Containing class structures, business logic, and inheritance.
2.  **💻 Main Source File (.cpp):** The cornerstone and entry point of the program.
3.  **🗄️ Data Files:** Organized text files used for persistent, encrypted data storage.
4.  **⚙️ Environment Configuration:** Solution and project files to be opened directly in (Visual Studio).

## **🚀 Quick Start Guide**
1.  **Download this repository to your local machine.**
2.  **Open the solution file (ending in `.sln`) using Visual Studio.**
3.  **All files will be automatically organized within the "Solution Explorer".**
4.  **Run the project (F5) to experience the full interactive system.**

---

<p align="center">
<b>✨ "Software is not just lines of code; it is the art of problem-solving and building systems that make life more organized and secure. I hope this project inspires every programmer striving for excellence." ✨</b>
</p>

---
















# <p align="center"> **💎 مشروع نظام إدارة البنك المتكامل - المستوى الحادي عشر 💎** </p>

**هذا المستودع يحتوي على كافة ملفات المصدر والنسخة النهائية والكاملة لنظام إدارة البنك. يُعد هذا المشروع التطبيق العملي الشامل والمتقدم الذي قمت فيه بتحويل كافة مفاهيم البرمجة الكائنية (OOP) التي تمت دراستها "نظرياً" في [المستوى العاشر](https://github.com/ammmrrr18-cloud/Programming-Foundations-Roadmap/tree/main/10-OOP-as-it-Should-Be-Concepts) إلى نظام واقعي متكامل يعمل بكفاءة عالية.**

---

### **💡 رحلة بناء المشروع (التدرج التعليمي):**
**هذا النظام لم يُبنَ دفعة واحدة، بل هو نتاج تدرج دقيق في التعلم والتطبيق. يمكنك رؤية مراحل التطور والتمارين البرمجية والأنظمة المصغرة التي سبقت هذا المشروع النهائي من خلال الرابط التالي:**
[**📂 مراحل بناء تطبيقات المستوى الحادي عشر (تدرج الدروس)**](https://github.com/ammmrrr18-cloud/Programming-Foundations-Roadmap/tree/main/11-OOP-as-it-Should-Be-Applications)
**حيث ستجد المستودع مجزءاً إلى مجلدات مستقلة، كل مجلد يمثل درساً أو مرحلة معينة في الكورس بملفاته الخاصة، مما يوضح التسلسل المنطقي لبناء الأنظمة المعقدة.**

---

## **🔵 شرح تفصيلي لأنظمة المشروع**
**تم تصميم النظام ليكون محاكاة واقعية لنظام بنكي احترافي، حيث تم تقسيم العمل إلى أنظمة برمجية متكاملة تضمن الكفاءة وسهولة الاستخدام:**

### **🔴 1. نظام إدارة العملاء والعمليات المالية (Clients & Transactions)**
**يُعد هذا النظام القلب النابض للبنك، حيث يدمج بين إدارة سجلات المودعين وتنفيذ كافة الحركات المالية بدقة متناهية:**
* **👤 إدارة الحسابات:** يوفر تحكماً كاملاً في "دورة حياة" حساب العميل (إضافة، تعديل، بحث، حذف).
* **💸 قسم العمليات المالية:** نظام فرعي مدمج مخصص لإدارة حركة الأموال، ويشمل:
    * **📥 الإيداع والسحب:** شاشات تفاعلية تتيح تنفيذ العمليات مع تحديث فوري للأرصدة.
    * **🔄 تحويل الأموال:** ميزة متطورة لنقل الرصيد بين حسابين مختلفين لحظياً.
    * **📊 كشف إجمالي الأرصدة:** شاشة مخصصة لتقديم تقرير شامل يجمع أرصدة كافة العملاء.

### **🟢 2. نظام إدارة المستخدمين وصلاحيات الوصول (User Permissions)**
**النظام مصمم ليكون آمناً جداً ويسمح بتعدد الأدوار الوظيفية داخل البنك:**
* **🔑 بوابة نفاذ آمنة:** شاشة دخول ذكية تحمي بيانات البنك وتدقق في هوية كل مستخدم (موظف).
* **🛡️ هيكلة الصلاحيات:** نظام احترافي يمنح كل موظف صلاحيات محددة بناءً على دوره الإداري.
* **👥 إدارة الكادر الإداري:** لوحة تحكم تتيح إضافة موظفين جدد أو حظرهم واستعراض صلاحياتهم.

### **🟡 3. نظام الصرافة وإدارة العملات الدولية (Currency Exchange Suite)**
**نظام فرعي متكامل لإدارة العملات الأجنبية وربطها بالدولار بشكل لحظي:**
* **🌍 مركز العملات:** قاعدة بيانات تضم العملات العالمية المسجلة في النظام وأسعار صرفها.
* **💹 تحديث الأسعار وحساب الصرف:** إمكانية تعديل أسعار الصرف يدوياً مع وجود حاسبة ذكية للتحويل السريع.

### **🟠 4. نظام الرقابة وسجلات النشاط (Logging & Monitoring)**
**يعمل النظام على توثيق كل كبيرة وصغيرة لضمان أعلى مستوى من الرقابة والشفافية:**
* **📝 سجل الدخول الشامل:** رصد دقيق لكل محاولة دخول للنظام (اسم المستخدم، التاريخ، الوقت).
* **📜 سجل التحويلات البنكية:** توثيق تاريخي لكل حركة مالية يوضح الأطراف والمبالغ والمستخدم المسؤول.

---

## **🔒 نظام حماية وتشفير البيانات (Data Encryption)**
**تم تدعيم النظام بطبقة حماية إضافية لضمان سرية البيانات الحساسة:**
* **🛡️ تشفير كلمات السر:** يتم تأمين كلمات السر الخاصة بالعملاء والمستخدمين قبل حفظها في الملفات.
* **💾 أمن الملفات النصية:** البيانات في ملفات `Clients.txt` و `Users.txt` تظهر بشكل مُشفر وغير مفهوم.
* **⚙️ محرك معالجة النصوص:** يعتمد النظام على فصيلة **`clsString`** التي تضم دوال التشفير وفك التشفير لحظياً.

---

## **🛠️ محتويات المستودع**
**يحتوي هذا المجلد على كل ما تحتاجه لتشغيل المشروع فوراً:**
1.  **📄 كافة ملفات الرأس (.h):** التي تحتوي على بناء الفصائل والمنطق البرمجي والوراثة.
2.  **💻 ملف التشغيل الرئيسي (.cpp):** وهو حجر الزاوية ونقطة انطلاق البرنامج.
3.  **🗄️ ملفات قواعد البيانات (Data):** ملفات نصية منظمة لتخزين البيانات بشكل دائم ومُشفر.
4.  **⚙️ ملفات إعدادات البيئة:** ملفات السولوشن والمشروع لفتحها مباشرة داخل (Visual Studio).

## **🚀 طريقة التشغيل السريعة**
1.  **قم بتحميل هذا المستودع بالكامل على جهازك.**
2.  **افتح ملف السولوشن (الذي ينتهي بامتداد `.sln`) باستخدام برنامج (Visual Studio).**
3.  **ستجد كافة الملفات منظمة تلقائياً داخل "مستكشف الحلول".**
4.  **قم ببدء التشغيل، وسيفتح معك النظام بكامل طاقته وألوانه التفاعلية.**

---

<p align="center">
<b>✨ "البرمجيات ليست مجرد أسطر من الكود، بل هي فن حل المشكلات وبناء الأنظمة التي تجعل الحياة أكثر تنظيماً وأماناً. أتمنى أن يكون هذا المشروع ملهماً لكل مبرمج يسعى للتميز." ✨</b>
</p>

---
