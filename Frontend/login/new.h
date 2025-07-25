<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>HRMS Dashboard</title>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css" />
  <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&display=swap" rel="stylesheet">
  <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
  <style>
    :root {
      --primary-color: #6366f1;
      --primary-light: #e0e7ff;
      --accent-color: #8b5cf6;
      --dark-color: #1e293b;
      --light-color: #ffffff;
      --gray-100: #f1f5f9;
      --gray-200: #e2e8f0;
      --gray-300: #cbd5e1;
      --gray-700: #334155;
      --header-height: 70px;
      --transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
      --shadow-sm: 0 1px 2px 0 rgba(0, 0, 0, 0.05);
      --shadow-md: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -1px rgba(0, 0, 0, 0.06);
      --shadow-lg: 0 10px 15px -3px rgba(0, 0, 0, 0.1), 0 4px 6px -2px rgba(0, 0, 0, 0.05);
      --shadow-xl: 0 20px 25px -5px rgba(0, 0, 0, 0.1), 0 10px 10px -5px rgba(0, 0, 0, 0.04);
    }

    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
      font-family: 'Inter', -apple-system, BlinkMacSystemFont, sans-serif;
    }

    body {
      display: flex;
      flex-direction: column;
      height: 100vh;
      overflow: hidden;
      background-color: var(--gray-100);
      color: var(--dark-color);
    }

    /* Header Styles */
    .header {
      display: flex;
      justify-content: space-between;
      align-items: center;
      height: var(--header-height);
      padding: 0 40px;
      background-color: var(--light-color);
      box-shadow: var(--shadow-sm);
      position: fixed;
      top: 0;
      left: 0;
      width: 100%;
      z-index: 100;
      transition: var(--transition);
    }

    .logo-container {
      padding: 4px;
      border-radius: 4px;
      transition: var(--transition);
      display: inline-flex;
      align-items: center;
      box-sizing: border-box;
      overflow: hidden;
    }

    .logo {
      height: 70px;
      transition: var(--transition);
    }

    .header-right {
      display: flex;
      align-items: center;
      gap: 16px;
    }

    .search-bar {
      display: flex;
      align-items: center;
      padding: 8px 7px;
      background-color: rgb(255, 255, 255);
      border-radius: 15px;
      width: 225px;
      margin-left: 50px;
      border: 0.5px solid #ccc;
      box-shadow: 0 2px 4px rgba(0, 0, 0, 0.5);
      position: relative;
    }

    .search-bar:hover {
      transform: translateY(-2px);
      background-color: white;
      border: 0.5px solid #ccc;
      box-shadow: 0 2px 4px rgba(0, 0, 0, 0.5);
    }

    .search-bar input {
      border: none;
      outline: none;
      padding: 3px;
      background-color: transparent;
      width: 90%;
      font-size: 0.9rem;
      color: black;
    }

    .search-bar input::placeholder {
      color: var(--gray-300);
    }

    .search-bar button {
      background: none;
      border: none;
      cursor: pointer;
      font-size: 1rem;
      color: var(--gray-700);
      transition: var(--transition);
    }

    .search-bar button:hover {
      color: var(--primary-color);
    }

    .autocomplete-dropdown {
      position: absolute;
      top: 100%;
      left: 0;
      right: 0;
      background-color: var(--light-color);
      border-radius: 8px;
      box-shadow: var(--shadow-md);
      max-height: 200px;
      overflow-y: auto;
      z-index: 1000;
      margin-top: 4px;
      display: none;
    }

    .autocomplete-item {
      display: flex;
      align-items: center;
      padding: 10px;
      cursor: pointer;
      font-size: 0.9rem;
      color: var(--gray-700);
      transition: var(--transition);
    }

    .autocomplete-item img {
      width: 20px;
      height: 20px;
      margin-right: 10px;
      object-fit: contain;
    }

    .autocomplete-item:hover {
      background-color: var(--gray-100);
      color: var(--primary-color);
    }

    .no-results {
      padding: 10px;
      font-size: 0.9rem;
      color: var(--gray-700);
      text-align: center;
    }

    .header-icon {
      position: relative;
      font-size: 1.3rem;
      cursor: pointer;
      color: var(--gray-700);
      transition: var(--transition);
      padding: 8px;
      border-radius: 8px;
      display: flex;
      align-items: center;
      justify-content: center;
    }

    .header-icon:hover {
      color: var(--primary-color);
      background-color: var(--gray-100);
    }

    .user-profile {
      display: flex;
      align-items: center;
      gap: 12px;
      cursor: pointer;
      padding: 6px 12px;
      border-radius: 8px;
      transition: var(--transition);
    }

    .user-profile:hover {
      background-color: var(--gray-100);
    }

    .user-name {
      font-weight: 500;
      font-size: 1.15rem;
    }

    .user-avatar {
      width: 36px;
      height: 36px;
      border-radius: 50%;
      object-fit: cover;
      border: 2px solid var(--gray-200);
      transition: var(--transition);
    }

    .user-profile:hover .user-avatar {
      border-color: var(--primary-color);
    }

    .toggle-btn {
      background: none;
      border: none;
      cursor: pointer;
      font-size: 1.2rem;
      color: var(--gray-700);
      padding: 8px;
      border-radius: 8px;
      transition: var(--transition);
      line-height: 1;
    }

    .toggle-btn:hover {
      color: var(--primary-color);
      background-color: var(--gray-100);
    }

    .toggle-btn:disabled {
      opacity: 0.5;
      cursor: not-allowed;
    }

    /* Radial Menu Styles */
    .radial-menu {
      position: fixed;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%) scale(0) rotate(0deg);
      width: 80px;
      height: 80px;
      background-color: var(--primary-color);
      border-radius: 50%;
      display: flex;
      justify-content: center;
      align-items: center;
      transition: transform 1s ease, width 0.3s ease, height 0.3s ease;
      z-index: 2000;
      box-shadow: var(--shadow-lg);
    }

    .radial-menu.active {
      transform: translate(-50%, -50%) scale(1) rotate(360deg);
      width: 340px;
      height: 340px;
    }

    .radial-menu.closing {
      transform: translate(-50%, -50%) scale(0) rotate(720deg);
    }

    .inner-circle {
      width: 140px;
      height: 140px;
      background-color: var(--light-color);
      border-radius: 50%;
      position: absolute;
      box-shadow: var(--shadow-md);
      display: flex;
      justify-content: center;
      align-items: center;
      transition: var(--transition);
      z-index: 2100;
    }

    .inner-circle select {
      width: 100px;
      padding: 8px;
      border: none;
      background: transparent;
      color: var(--primary-color);
      font-size: 18px;
      font-weight: 600;
      cursor: pointer;
      outline: none;
      transition: var(--transition);
      text-align: center;
      appearance: none;
      -webkit-appearance: none;
      -moz-appearance: none;
    }

    .inner-circle select:hover {
      color: var(--accent-color);
    }

    .inner-circle select option {
      background-color: var(--light-color);
      color: var(--dark-color);
    }

    .emp-menu, .hr-menu {
      position: absolute;
      width: 100%;
      height: 100%;
      display: none;
    }

    .emp-menu.active, .hr-menu.active {
      display: block;
    }

    .menu-item {
      position: absolute;
      width: 40px;
      height: 40px;
      background-color: var(--light-color);
      border-radius: 50%;
      display: flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      transition: all 0.3s ease;
      box-shadow: var(--shadow-sm);
    }

    .menu-item:hover {
      background-color: var(--gray-100);
    }

    .menu-item img {
      width: 24px;
      height: 24px;
      object-fit: contain;
    }

    /* Tooltip Styles */
    .tooltip {
      position: absolute;
      background-color: var(--dark-color);
      color: var(--light-color);
      padding: 5px 10px;
      border-radius: 4px;
      font-size: 12px;
      white-space: nowrap;
      opacity: 0;
      transition: opacity 0.2s ease;
      pointer-events: none;
      z-index: 2100;
      transform: translate(-50%, -50%);
    }

    .menu-item:hover .tooltip {
      opacity: 1;
    }

    /* Tooltip positions for EMP modules */
    .emp-menu .menu-item[data-module="emp_attendance"] .tooltip { transform: translate(-50%, -100%); }
    .emp-menu .menu-item[data-module="emp_leave"] .tooltip { transform: translate(-40%, -90%); }
    .emp-menu .menu-item[data-module="emp_wfh"] .tooltip { transform: translate(-30%, -70%); }
    .emp-menu .menu-item[data-module="emp_payslip"] .tooltip { transform: translate(-20%, -50%); }
    .emp-menu .menu-item[data-module="emp_tasks"] .tooltip { transform: translate(-10%, -30%); }
    .emp-menu .menu-item[data-module="emp_helpdesk"] .tooltip { transform: translate(0%, -20%); }
    .emp-menu .menu-item[data-module="emp_Onboarding"] .tooltip { transform: translate(10%, -10%); }
    .emp-menu .menu-item[data-module="emp_benefits"] .tooltip { transform: translate(20%, 0%); }
    .emp-menu .menu-item[data-module="emp_Appraisal"] .tooltip { transform: translate(30%, 10%); }
    .emp-menu .menu-item[data-module="emp_notifications"] .tooltip { transform: translate(40%, 20%); }
    .emp-menu .menu-item[data-module="emp_asset"] .tooltip { transform: translate(50%, 30%); }
    .emp-menu .menu-item[data-module="emp_bonus"] .tooltip { transform: translate(50%, 40%); }
    .emp-menu .menu-item[data-module="emp_joblists"] .tooltip { transform: translate(40%, 50%); }
    .emp-menu .menu-item[data-module="emp_claim"] .tooltip { transform: translate(30%, 60%); }
    .emp-menu .menu-item[data-module="emp_offboarding"] .tooltip { transform: translate(20%, 70%); }
    .emp-menu .menu-item[data-module="emp_jobapplication"] .tooltip { transform: translate(10%, 80%); }
    .emp-menu .menu-item[data-module="emp_offerletter"] .tooltip { transform: translate(0%, 90%); }
    .emp-menu .menu-item[data-module="emp_logout"] .tooltip { transform: translate(-10%, 100%); }

    /* Tooltip positions for HR modules */
    .hr-menu .menu-item[data-module="hr_attendance"] .tooltip { transform: translate(-50%, -100%); }
    .hr-menu .menu-item[data-module="hr_leave"] .tooltip { transform: translate(-40%, -90%); }
    .hr-menu .menu-item[data-module="hr_wfh"] .tooltip { transform: translate(-30%, -70%); }
    .hr-menu .menu-item[data-module="hr_payslip"] .tooltip { transform: translate(-20%, -50%); }
    .hr-menu .menu-item[data-module="hr_tasks"] .tooltip { transform: translate(-10%, -30%); }
    .hr-menu .menu-item[data-module="hr_helpdesk"] .tooltip { transform: translate(0%, -20%); }
    .hr-menu .menu-item[data-module="hr_employeemanagement"] .tooltip { transform: translate(10%, -10%); }
    .hr-menu .menu-item[data-module="hr_benefits"] .tooltip { transform: translate(20%, 0%); }
    .hr-menu .menu-item[data-module="hr_appraisal"] .tooltip { transform: translate(30%, 10%); }
    .hr-menu .menu-item[data-module="hr_notifications"] .tooltip { transform: translate(40%, 20%); }
    .hr-menu .menu-item[data-module="hr_asset"] .tooltip { transform: translate(50%, 30%); }
    .hr-menu .menu-item[data-module="hr_bonus"] .tooltip { transform: translate(50%, 40%); }
    .hr-menu .menu-item[data-module="hr_joblists"] .tooltip { transform: translate(40%, 50%); }
    .hr-menu .menu-item[data-module="hr_claim"] .tooltip { transform: translate(30%, 60%); }
    .hr-menu .menu-item[data-module="hr_offboarding"] .tooltip { transform: translate(20%, 70%); }
    .hr-menu .menu-item[data-module="hr_jobapplication"] .tooltip { transform: translate(10%, 80%); }
    .hr-menu .menu-item[data-module="hr_Onboarding"] .tooltip { transform: translate(0%, 90%); }
    .hr-menu .menu-item[data-module="hr_logout"] .tooltip { transform: translate(-10%, 100%); }

    /* Main Content */
    .main-content {
      margin-top: var(--header-height);
      height: calc(100vh - var(--header-height));
      width: 100%;
      transition: filter 0.3s ease;
    }

    .main-content iframe {
      width: 100%;
      height: 100%;
      border: none;
      background-color: var(--light-color);
    }

    /* Blur Effect */
    .menu-open .main-content {
      filter: blur(25px);
    }

    /* Dark Mode Styles */
    body.dark-mode {
      background-color: #000000;
      color: #f8fafc;
    }

    body.dark-mode .header {
      background-color: #000000;
      box-shadow: 2px 0 8px rgba(0, 0, 0, 0.3);
    }

    body.dark-mode .logo-container {
      background-color: #ffffff;
      padding: 0px;
      border-radius: 20px;
      display: inline-flex;
      align-items: center;
      box-sizing: border-box;
      overflow: hidden;
    }

    .dark-mode .search-bar {
      background-color: #000000b0;
      border-radius: 20px;
      box-shadow: 0 2px 4px rgba(197, 190, 255, 0.865);
    }

    .dark-mode .search-bar:hover {
      background-color: black;
      border-radius: 20px;
      color: white;
      box-shadow: 0 2px 4px rgba(197, 190, 255, 0.865);
    }

    .dark-mode .search-bar input {
      color: #ffffff;
    }

    .dark-mode .search-bar input::placeholder {
      color: #a0a0a0;
    }

    .dark-mode .search-bar button {
      color: #ffffff;
    }

    .dark-mode .autocomplete-dropdown {
      background-color: #1e293b;
    }

    .dark-mode .autocomplete-item {
      color: #f8fafc;
    }

    .dark-mode .autocomplete-item:hover {
      background-color: #334155;
      color: var(--primary-color);
    }

    .dark-mode .no-results {
      color: #f8fafc;
    }

    body.dark-mode .header-icon,
    body.dark-mode .toggle-btn {
      color: #ffffff;
    }

    body.dark-mode .header-icon:hover,
    body.dark-mode .toggle-btn:hover {
      background-color: #333333;
      color: var(--primary-color);
    }

    body.dark-mode .user-profile:hover {
      background-color: #333333;
    }

    body.dark-mode .user-avatar {
      border-color: #475569;
    }

    body.dark-mode .inner-circle {
      background-color: #570057;
      color: white;
    }

    body.dark-mode .inner-circle select {
      background: transparent;
      color: #ffffff;
    }

    body.dark-mode .inner-circle select:hover {
      color: var(--accent-color);
    }

    body.dark-mode .inner-circle select option {
      background-color: #444444;
      color: #ffffff;
    }

    body.dark-mode .menu-item {
      background-color: #ffffff;
    }

    body.dark-mode .menu-item:hover {
      background-color: #f8fcff;
    }

    /* Alert Styles */
    .alert {
      position: fixed;
      top: 20px;
      right: 20px;
      padding: 16px 24px;
      border-radius: 12px;
      color: #fff;
      font-size: 0.95rem;
      display: flex;
      align-items: center;
      gap: 12px;
      box-shadow: var(--shadow-xl);
      z-index: 1000;
      animation: slideInRight 0.4s cubic-bezier(0.16, 1, 0.3, 1), 
                 slideOutRight 0.5s cubic-bezier(0.5, 0, 0.75, 0) 2.5s forwards;
      max-width: 350px;
      backdrop-filter: blur(10px);
      border: 1px solid rgba(255, 255, 255, 0.1);
    }

    .alert i {
      font-size: 1.2rem;
    }

    .alert.error {
      background: rgba(239, 68, 68, 0.9);
    }

    .alert.success {
      background: rgba(16, 185, 129, 0.9);
    }

    .alert.warning {
      background: rgba(245, 158, 11, 0.9);
    }

    /* Animations */
    @keyframes slideInRight {
      from { transform: translateX(100%); opacity: 0; }
      to { transform: translateX(0); opacity: 1; }
    }

    @keyframes slideOutRight {
      from { transform: translateX(0); opacity: 1; }
      to { transform: translateX(100%); opacity: 0; }
    }

    /* Loading Animation */
    .skeleton {
      background-color: var(--gray-200);
      border-radius: 6px;
      animation: pulse 2s cubic-bezier(0.4, 0, 0.6, 1) infinite;
    }

    @keyframes pulse {
      0%, 100% { opacity: 1; }
      50% { opacity: 0.5; }
    }

    body.dark-mode .skeleton {
      background-color: #333333;
    }

    /* Login Page Styles */
    .login-body {
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
      overflow: hidden;
      background-color: #f0f2f5;
    }

    .container {
      position: relative;
      width: 100%;
      height: 100vh;
      background-color: rgb(255, 255, 255);
      overflow: hidden;
    }

    .big-circle {
      position: absolute;
      width: 1200px;
      height: 1200px;
      background-color: #0077ff;
      border-radius: 50%;
      top: -500px;
      left: -500px;
      opacity: 0.9;
    }

    .small-circle {
      position: absolute;
      width: 140px;
      height: 140px;
      background-color: #0055cc;
      border-radius: 50%;
      bottom: 20px;
      left: 20px;
      box-shadow: 0 0 15px rgba(255, 255, 255, 0.8), inset 0 0 10px rgba(255, 255, 255, 0.5);
      animation: pulse 2s infinite;
    }

    .overlay-circle {
      position: absolute;
      width: 160px;
      height: 160px;
      background-color: #0055cc;
      border-radius: 50%;
      top: 220px;
      left: 350px;
      box-shadow: 0 0 15px rgba(255, 255, 255, 0.8), inset 0 0 10px rgba(255, 255, 255, 0.5);
      animation: float 3s ease-in-out infinite;
    }

    @keyframes float {
      0%, 100% { transform: translateY(0); }
      50% { transform: translateY(-20px); }
    }

    .right-bottom-circle {
      position: absolute;
      width: 120px;
      height: 120px;
      background-color: #0055cc;
      border-radius: 50%;
      bottom: -42px;
      right: -42px;
      box-shadow: 0 0 15px rgba(255, 255, 255, 0.8), inset 0 0 10px rgba(255, 255, 255, 0.5);
      animation: pulse 2s infinite;
    }

    .welcome-text {
      position: absolute;
      top: 35%;
      left: 2%;
      font-size: 18px;
      font-weight: bold;
      color: rgb(255, 255, 255);
      overflow: hidden;
      white-space: nowrap;
    }

    .welcome-text span {
      font-size: 31px;
      color: rgb(255, 255, 255);
      display: inline-block;
      overflow: hidden;
      white-space: nowrap;
      width: 0;
      animation: typing 3s steps(20, end) forwards;
    }

    .welcome-text p {
      font-size: 18px;
      color: white;
      opacity: 0;
      animation: fadeIn 2s ease-in forwards;
      animation-delay: 3s;
    }

    @keyframes typing {
      from { width: 0; }
      to { width: 370px; }
    }

    @keyframes fadeIn {
      from { opacity: 0; transform: translateY(10px); }
      to { opacity: 1; transform: translateY(0); }
    }

    .login-container {
      position: absolute;
      top: 50%;
      right: 16%;
      transform: translateY(-50%);
      width: 530px;
      color: black;
      text-align: center;
      background: rgba(255, 255, 255, 0.95);
      padding: 30px;
      border-radius: 10px;
      box-shadow: 0 4px 20px rgba(0, 0, 0, 0.1);
      box-sizing: border-box;
    }

    .login-container h2 {
      margin-bottom: 10px;
      font-size: 30px;
      color: #0077ff;
    }

    .error-message {
      color: #ff3333;
      font-size: 12px;
      margin-bottom: 20px;
      text-align: center;
      min-height: 14px;
    }

    .input-container {
      position: relative;
      margin-bottom: 25px;
    }

    .input-container input {
      width: 100%;
      padding: 10px 30px 10px 10px;
      border: none;
      border-bottom: 2px solid #000000;
      background: transparent;
      font-size: 16px;
      outline: none;
      transition: border-color 0.3s;
      box-sizing: border-box;
    }

    .input-container input:focus {
      border-bottom-color: #0077ff;
    }

    .input-container label {
      position: absolute;
      top: 10px;
      left: 10px;
      font-size: 18px;
      color: #000000;
      pointer-events: none;
      transition: all 0.3s ease;
    }

    .input-container input:focus + label,
    .input-container input:not(:placeholder-shown) + label {
      top: -10px;
      font-size: 15px;
      color: #0077ff;
    }

    .password-container {
      position: relative;
    }

    .password-container .eye-icon {
      position: absolute;
      right: 10px;
      top: 50%;
      transform: translateY(-50%);
      cursor: pointer;
      color: #0077ff;
      font-size: 18px;
    }

    .login-button {
      width: 100%;
      padding: 12px;
      background-color: #0077ff;
      color: white;
      border: none;
      border-radius: 5px;
      font-size: 18px;
      cursor: pointer;
      transition: background-color 0.3s, transform 0.2s;
      margin-top: 10px;
    }

    .login-button:hover {
      background-color: #0055cc;
      transform: scale(1.02);
    }

    .links {
      margin-top: 15px;
      font-size: 16px;
    }

    .links a {
      color: #0077ff;
      text-decoration: none;
      margin: 0 5px;
      transition: color 0.3s;
    }

    .links a:hover {
      color: #0055cc;
      text-decoration: underline;
    }

    /* Modal Styles */
    .modal {
      position: fixed;
      top: 0;
      left: 0;
      width: 100%;
      height: 100vh;
      background-color: rgba(0, 0, 0, 0.5);
      display: flex;
      justify-content: center;
      align-items: center;
      z-index: 2000;
      display: none;
    }

    .modal-content {
      background-color: var(--light-color);
      padding: 20px;
      border-radius: 8px;
      width: 90%;
      max-width: 400px;
      box-shadow: var(--shadow-xl);
      position: relative;
    }

    .modal-close {
      position: absolute;
      top: 10px;
      right: 10px;
      background: none;
      border: none;
      font-size: 1.2rem;
      cursor: pointer;
      color: var(--gray-700);
    }

    .modal-close:hover {
      color: var(--primary-color);
    }

    .modal-title {
      font-size: 1.5rem;
      margin-bottom: 20px;
      color: var(--dark-color);
    }

    .modal-body {
      max-height: 60vh;
      overflow-y: auto;
      font-size: 0.9rem;
      color: var(--gray-700);
    }

    .modal-body p {
      margin-bottom: 10px;
      display: flex;
      justify-content: space-between;
    }

    .modal-body strong {
      flex: 0 0 120px;
    }

    body.dark-mode .modal-content {
      background-color: #1e293b;
      color: #f8fafc;
    }

    body.dark-mode .modal-close {
      color: #f8fafc;
    }

    body.dark-mode .modal-close:hover {
      color: var(--primary-color);
    }

    body.dark-mode .modal-body {
      color: #f8fafc;
    }

    /* Responsive Styles */
    @media (max-width: 1024px) {
      .search-bar {
        width: 240px;
      }

      .big-circle {
        width: 800px;
        height: 800px;
        top: -400px;
        left: -400px;
      }

      .overlay-circle {
        top: 180px;
        left: 250px;
        width: 120px;
        height: 120px;
      }

      .login-container {
        right: 10%;
        width: 300px;
        padding: 20px;
      }

      .welcome-text {
        top: 30%;
        left: 5%;
      }

      .welcome-text span {
        font-size: 28px;
      }
    }

    @media (max-width: 768px) {
      .header {
        padding: 0 20px;
      }

      .search-bar {
        width: 200px;
        margin-left: 0;
      }

      .logo {
        height: 36px;
      }

      .big-circle {
        width: 600px;
        height: 600px;
        top: -300px;
        left: -300px;
      }

      .small-circle {
        width: 80px;
        height: 80px;
        bottom: 10px;
        left: 10px;
      }

      .overlay-circle {
        top: 150px;
        left: 50%;
        transform: translateX(-50%);
        width: 100px;
        height: 100px;
      }

      .right-bottom-circle {
        width: 100px;
        height: 100px;
        bottom: -30px;
        right: -30px;
      }

      .welcome-text {
        top: 20%;
        left: 50%;
        transform: translateX(-50%);
        text-align: center;
      }

      .welcome-text span {
        font-size: 24px;
      }

      .welcome-text p {
        font-size: 16px;
      }

      .login-container {
        top: 50%;
        right: 50%;
        transform: translate(50%, -50%);
        width: 90%;
        max-width: 280px;
        padding: 15px;
      }

      .login-container h2 {
        font-size: 24px;
      }

      .inner-circle select {
        width: 80px;
        font-size: 16px;
        padding: 6px;
      }
    }

    @media (max-width: 640px) {
      .search-bar {
        display: none;
      }

      .user-name {
        display: none;
      }

      .user-profile {
        padding: 0;
      }

      .header-icon,
      .toggle-btn {
        padding: 6px;
      }
    }

    @media (max-width: 480px) {
      .big-circle {
        width: 500px;
        height: 500px;
        top: -250px;
        left: -250px;
      }

      .small-circle {
        width: 60px;
        height: 60px;
      }

      .overlay-circle {
        width: 80px;
        height: 80px;
        top: 120px;
      }

      .right-bottom-circle {
        width: 80px;
        height: 80px;
        bottom: -20px;
        right: -20px;
      }

      .welcome-text span {
        font-size: 20px;
      }

      .welcome-text p {
        font-size: 14px;
      }

      .login-container {
        width: 95%;
        padding: 10px;
      }

      .login-container h2 {
        font-size: 20px;
      }

      .input-container input {
        font-size: 14px;
        padding: 8px 25px 8px 8px;
      }

      .input-container label {
        font-size: 16px;
      }

      .eye-icon {
        font-size: 16px;
      }

      .login-button {
        font-size: 16px;
        padding: 10px;
      }

      .error-message {
        font-size: 11px;
      }

      .inner-circle select {
        width: 70px;
        font-size: 14px;
        padding: 5px;
      }
    }

    /* Hide/Show Classes */
    .hidden {
      display: none;
    }
  </style>
</head>
<body id="appBody" class="login-body">
  <!-- Login Page Content -->
  <div id="loginView" class="container">
    <div class="big-circle"></div>
    <div class="small-circle"></div>
    <div class="overlay-circle"></div>
    <div class="right-bottom-circle"></div>

    <div class="welcome-text">
      <span>Astrolite Tech Solutions</span>
      <p>For a bright future, we stand together</p>
    </div>

    <div class="login-container">
      <h2>Login</h2>
      <div id="error-message" class="error-message"></div>
      <form id="loginForm">
        <div class="input-container">
          <input type="email" id="email" placeholder=" " required>
          <label for="email">Email</label>
        </div>
        <div class="input-container password-container">
          <input type="password" id="password" placeholder=" " required>
          <label for="password">Password</label>
          <i class="fas fa-eye eye-icon" id="eyeIcon"></i>
        </div>
        <button type="submit" class="login-button">Login</button>
      </form>
      <div class="links">
        <a href="http://51.20.37.128:8013/">Sign Up</a> | <a href="http://51.20.37.128:8010">Forgot Password?</a>
      </div>
    </div>
  </div>

  <!-- Dashboard Content -->
  <div id="dashboardView" class="hidden">
    <header class="header">
      <div class="logo-container">
        <img src="logo.png" alt="Company Logo" class="logo" />
      </div>
      <div class="header-right">
        <div class="search-bar" id="searchBar">
          <input type="text" id="searchInput" placeholder="Search employees, reports..." />
          <button id="searchButton"><i class="fas fa-search"></i></button>
          <div class="autocomplete-dropdown" id="autocompleteDropdown"></div>
        </div>
        <div class="header-icon" id="themeToggle" title="Toggle theme">
          <i class="fas fa-moon"></i>
        </div>
        <div class="header-icon" id="infoIcon" title="Employee Details">
          <i class="fas fa-info-circle"></i>
        </div>
        <div class="user-profile">
          <div class="skeleton" style="width:36px;height:36px;border-radius:50%;" id="avatarSkeleton"></div>
          <img src="https://img.icons8.com/fluency/48/user-male-circle.png" alt="User Avatar" class="user-avatar" id="userAvatar" style="display:none;" />
          <span class="user-name" id="userName">Loading...</span>
        </div>
        <button class="toggle-btn" id="toggleBtn">
          <i class="fas fa-bars"></i>
        </button>
      </div>
    </header>

    <!-- Radial Menu -->
    <div class="radial-menu" id="radialMenu">
      <div class="inner-circle" id="innerCircle">
        <select id="moduleSelector">
          <option value="emp">EMP</option>
          <option value="hr">HR</option>
        </select>
      </div>
      <div class="emp-menu" id="empMenu">
        <div class="menu-item" data-module="emp_attendance">
          <img src="https://img.icons8.com/color/24/calendar--v1.png" alt="Attendance"><span class="tooltip">Attendance</span>
        </div>
        <div class="menu-item" data-module="emp_leave">
          <img src="https://img.icons8.com/color/24/beach.png" alt="Leave"><span class="tooltip">Leave</span>
        </div>
        <div class="menu-item" data-module="emp_wfh">
          <img src="https://img.icons8.com/color/24/laptop.png" alt="WFH"><span class="tooltip">WFH</span>
        </div>
        <div class="menu-item" data-module="emp_payslip">
          <img src="https://img.icons8.com/color/24/money-bag.png" alt="Payslip"><span class="tooltip">Payslip</span>
        </div>
        <div class="menu-item" data-module="emp_tasks">
          <img src="https://img.icons8.com/color/24/task-completed.png" alt="Tasks"><span class="tooltip">Tasks</span>
        </div>
        <div class="menu-item" data-module="emp_helpdesk">
          <img src="https://img.icons8.com/color/24/help.png" alt="Help Desk"><span class="tooltip">Help Desk</span>
        </div>
        <div class="menu-item" data-module="emp_Onboarding">
          <img src="https://cdn-icons-png.freepik.com/256/13730/13730909.png?semt=ais_hybrid" alt="Onboarding"><span class="tooltip">Onboarding</span>
        </div>
        <div class="menu-item" data-module="emp_benefits">
          <img src="https://cdn-icons-png.flaticon.com/512/8655/8655563.png" alt="Benefits"><span class="tooltip">Benefits</span>
        </div>
        <div class="menu-item" data-module="emp_Appraisal">
          <img src="https://cdn-icons-png.flaticon.com/512/12278/12278438.png" alt="Appraisal"><span class="tooltip">Appraisal</span>
        </div>
        <div class="menu-item" data-module="emp_notifications">
          <img src="https://cdn-icons-png.flaticon.com/512/4658/4658755.png" alt="Notifications"><span class="tooltip">Notifications</span>
        </div>
        <div class="menu-item" data-module="emp_asset">
          <img src="https://cdn-icons-png.flaticon.com/512/3135/3135771.png" alt="Assets"><span class="tooltip">Assets</span>
        </div>
        <div class="menu-item" data-module="emp_bonus">
          <img src="https://cdn-icons-png.flaticon.com/512/6303/6303173.png" alt="Bonus"><span class="tooltip">Bonus</span>
        </div>
        <div class="menu-item" data-module="emp_joblists">
          <img src="https://cdn-icons-png.flaticon.com/512/4116/4116684.png" alt="Job Listings"><span class="tooltip">Job Listings</span>
        </div>
        <div class="menu-item" data-module="emp_claim">
          <img src="https://cdn-icons-png.flaticon.com/512/12194/12194787.png" alt="Claims"><span class="tooltip">Claims</span>
        </div>
        <div class="menu-item" data-module="emp_offboarding">
          <img src="https://cdn-icons-png.freepik.com/256/8265/8265009.png?semt=ais_hybrid" alt="Offboarding"><span class="tooltip">Offboarding</span>
        </div>
        <div class="menu-item" data-module="emp_jobapplication">
          <img src="https://cdn-icons-png.flaticon.com/512/13441/13441753.png" alt="Job Application"><span class="tooltip">Job Application</span>
        </div>
        <div class="menu-item" data-module="emp_offerletter">
          <img src="https://cdn-icons-png.freepik.com/256/4654/4654143.png?semt=ais_hybrid" alt="Offer Letter"><span class="tooltip">Offer Letter</span>
        </div>
        <div class="menu-item" data-module="emp_logout">
          <img src="https://img.icons8.com/color/24/logout-rounded-left.png" alt="Logout"><span class="tooltip">Logout</span>
        </div>
      </div>
      <div class="hr-menu" id="hrMenu">
        <div class="menu-item" data-module="hr_attendance">
          <img src="https://img.icons8.com/color/24/calendar--v1.png" alt="Attendance"><span class="tooltip">Attendance</span>
        </div>
        <div class="menu-item" data-module="hr_leave">
          <img src="https://img.icons8.com/color/24/beach.png" alt="Leave"><span class="tooltip">Leave</span>
        </div>
        <div class="menu-item" data-module="hr_wfh">
          <img src="https://img.icons8.com/color/24/laptop.png" alt="WFH"><span class="tooltip">WFH</span>
        </div>
        <div class="menu-item" data-module="hr_payslip">
          <img src="https://img.icons8.com/color/24/money-bag.png" alt="Payslip"><span class="tooltip">Payslip</span>
        </div>
        <div class="menu-item" data-module="hr_tasks">
          <img src="https://img.icons8.com/color/24/task-completed.png" alt="Tasks"><span class="tooltip">Tasks</span>
        </div>
        <div class="menu-item" data-module="hr_helpdesk">
          <img src="https://img.icons8.com/color/24/help.png" alt="Help Desk"><span class="tooltip">Help Desk</span>
        </div>
        <div class="menu-item" data-module="hr_employeemanagement">
          <img src="https://img.icons8.com/color/24/conference-call.png" alt="Employee Management"><span class="tooltip">Employee Management</span>
        </div>
        <div class="menu-item" data-module="hr_benefits">
          <img src="https://cdn-icons-png.flaticon.com/512/11113/11113093.png" alt="Benefits"><span class="tooltip">Benefits</span>
        </div>
        <div class="menu-item" data-module="hr_appraisal">
          <img src="https://cdn-icons-png.flaticon.com/512/11112/11112856.png" alt="Appraisal"><span class="tooltip">Appraisal</span>
        </div>
        <div class="menu-item" data-module="hr_notifications">
          <img src="https://img.icons8.com/color/24/appointment-reminders.png" alt="Notifications"><span class="tooltip">Notifications</span>
        </div>
        <div class="menu-item" data-module="hr_asset">
          <img src="https://img.icons8.com/color/24/feedback.png" alt="Assets"><span class="tooltip">Assets</span>
        </div>
        <div class="menu-item" data-module="hr_bonus">
          <img src="https://img.icons8.com/color/24/document.png" alt="Bonus"><span class="tooltip">Bonus</span>
        </div>
        <div class="menu-item" data-module="hr_joblists">
          <img src="https://img.icons8.com/color/24/training.png" alt="Job Listings"><span class="tooltip">Job Listings</span>
        </div>
        <div class="menu-item" data-module="hr_claim">
          <img src="https://cdn-icons-png.freepik.com/256/14252/14252153.png?semt=ais_hybrid" alt="Claims"><span class="tooltip">Claims</span>
        </div>
        <div class="menu-item" data-module="hr_offboarding">
          <img src="https://img.icons8.com/?size=192&id=E1XHpaUoWFxv&format=png" alt="Offboarding"><span class="tooltip">Offboarding</span>
        </div>
        <div class="menu-item" data-module="hr_jobapplication">
          <img src="https://cdn-icons-png.flaticon.com/512/16995/16995294.png" alt="Job Application"><span class="tooltip">Job Application</span>
        </div>
        <div class="menu-item" data-module="hr_Onboarding">
          <img src="https://cdn-icons-png.flaticon.com/512/3862/3862949.png" alt="Onboarding"><span class="tooltip">Onboarding</span>
        </div>
        <div class="menu-item" data-module="hr_logout">
          <img src="https://img.icons8.com/color/24/logout-rounded-left.png" alt="Logout"><span class="tooltip">Logout</span>
        </div>
      </div>
    </div>

    <!-- Main Content -->
    <main class="main-content" id="mainContent">
      <iframe id="contentFrame" src="http://51.20.37.128:7999/" loading="lazy"></iframe>
    </main>

    <!-- Employee Details Modal -->
    <div class="modal" id="empDetailsModal">
      <div class="modal-content">
        <button class="modal-close" id="modalClose">×</button>
        <h2 class="modal-title">Employee Details</h2>
        <div class="modal-body" id="empDetailsContent">
          <p><strong>Name:</strong> <span id="empName">Loading...</span></p>
          <p><strong>Email:</strong> <span id="empEmail">Loading...</span></p>
          <p><strong>Employee ID:</strong> <span id="empId">Loading...</span></p>
          <p><strong>Department:</strong> <span id="empDepartment">Loading...</span></p>
          <p><strong>Role:</strong> <span id="empRole">Loading...</span></p>
        </div>
      </div>
    </div>
  </div>

<script>
document.addEventListener('DOMContentLoaded', async () => {
  const config = {
    apiBaseUrl: 'http://51.20.37.128:3404/api',
    authUrls: {
      login: 'http://51.20.37.128:8012',
      signup: 'http://51.20.37.128:8013/',
      forgotPassword: 'http://51.20.37.128:8010'
    },
    modules: {
      emp_attendance: 'http://51.20.37.128:8051/',
      emp_leave: 'leave.html',
      emp_wfh: 'http://51.20.37.128:8025/',
      emp_payslip: 'http://51.20.37.128:7019/',
      emp_tasks: 'http://51.20.37.128:8045/',
      emp_helpdesk: 'http://51.20.37.128:8049/',
      emp_Onboarding: 'http://51.20.37.128:8039/',
      emp_benefits: 'http://51.20.37.128:8043/',
      emp_Appraisal: 'http://51.20.37.128:8014/',
      emp_notifications: 'http://51.20.37.128:8053/',
      emp_asset: 'http://51.20.37.128:8047/',
      emp_bonus: 'http://51.20.37.128:8055/',
      emp_joblists: 'http://51.20.37.128:8020/',
      emp_claim: 'http://51.20.37.128:8027/',
      emp_offboarding: 'http://51.20.37.128:8041/',
      emp_jobapplication: 'http://51.20.37.128:8031/',
      emp_offerletter: 'http://51.20.37.128:8033/',
      emp_logout: '',
      hr_attendance: 'http://51.20.37.128:8052/',
      hr_leave: 'leave.html',
      hr_wfh: 'http://51.20.37.128:8026/',
      hr_payslip: 'http://51.20.37.128:7020/',
      hr_tasks: 'http://51.20.37.128:8046/',
      hr_helpdesk: 'http://51.20.37.128:8050/',
      hr_Onboarding: 'http://51.20.37.128:8040/',
      hr_employeemanagement: 'http://51.20.37.128:8036/',
      hr_benefits: 'http://51.20.37.128:8044/',
      hr_appraisal: 'http://51.20.37.128:8015/',
      hr_notifications: 'http://51.20.37.128:8054/',
      hr_asset: 'http://51.20.37.128:8048/',
      hr_bonus: 'http://51.20.37.128:8056/',
      hr_joblists: 'http://51.20.37.128:8021/',
      hr_claim: 'http://51.20.37.128:8028/',
      hr_offboarding: 'http://51.20.37.128:8042/',
      hr_jobapplication: 'http://51.20.37.128:8032/',
      hr_logout: ''
    },
    sessionCheckInterval: 300000
  };

  const elements = {
    appBody: document.getElementById('appBody'),
    loginView: document.getElementById('loginView'),
    dashboardView: document.getElementById('dashboardView'),
    loginForm: document.getElementById('loginForm'),
    emailInput: document.getElementById('email'),
    passwordInput: document.getElementById('password'),
    errorMessage: document.getElementById('error-message'),
    eyeIcon: document.getElementById('eyeIcon'),
    loginButton: document.querySelector('.login-button'),
    contentFrame: document.getElementById('contentFrame'),
    avatarSkeleton: document.getElementById('avatarSkeleton'),
    userAvatar: document.getElementById('userAvatar'),
    userName: document.getElementById('userName'),
    themeToggle: document.getElementById('themeToggle'),
    toggleBtn: document.getElementById('toggleBtn'),
    radialMenu: document.getElementById('radialMenu'),
    innerCircle: document.getElementById('innerCircle'),
    moduleSelector: document.getElementById('moduleSelector'),
    empMenu: document.getElementById('empMenu'),
    hrMenu: document.getElementById('hrMenu'),
    mainContent: document.getElementById('mainContent'),
    searchInput: document.getElementById('searchInput'),
    searchButton: document.getElementById('searchButton'),
    searchBar: document.getElementById('searchBar'),
    autocompleteDropdown: document.getElementById('autocompleteDropdown'),
    empDetailsModal: document.getElementById('empDetailsModal'),
    modalClose: document.getElementById('modalClose'),
    empName: document.getElementById('empName'),
    empEmail: document.getElementById('empEmail'),
    empId: document.getElementById('empId'),
    empDepartment: document.getElementById('empDepartment'),
    empRole: document.getElementById('empRole'),
    infoIcon: document.getElementById('infoIcon')
  };

  const state = {
    user: null,
    token: null,
    refreshToken: null,
    isDarkMode: false,
    isAuthenticated: false,
    isToggling: false,
    currentMenu: 'emp',
    personnelDetails: null
  };

  const utils = {
    showAlert: (type, message) => {
      const alert = document.createElement('div');
      alert.className = `alert ${type}`;
      const icons = {
        success: 'fa-check-circle',
        error: 'fa-exclamation-circle',
        warning: 'fa-exclamation-triangle',
        info: 'fa-info-circle'
      };
      alert.innerHTML = `<i class="fas ${icons[type] || icons.info}"></i> ${message}`;
      document.body.appendChild(alert);
      setTimeout(() => {
        alert.style.animation = 'slideOutRight 0.5s ease-out forwards';
        setTimeout(() => alert.remove(), 500);
      }, 3000);
    },

    handleApiError: (error) => {
      console.error('API Error:', error);
      utils.showAlert('error', error.message || 'An error occurred');
      if (error.status === 401) {
        core.verifySession();
      }
    },

    getCookie: (name) => {
      const value = `; ${document.cookie}`;
      const parts = value.split(`; ${name}=`);
      if (parts.length === 2) return parts.pop().split(';').shift();
    },

    logToServer: async (message, level = 'info') => {
      try {
        await fetch(`${config.apiBaseUrl}/log-client`, {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ message, level })
        });
      } catch (err) {
        console.error('Failed to log to server:', err);
      }
    },

    fetchWithAuth: async (url, options = {}) => {
      try {
        let token = utils.getCookie('accessToken') || state.token;
        if (!token) {
          throw { status: 401, message: 'No authentication token found' };
        }

        const response = await fetch(`${config.apiBaseUrl}${url}`, {
          ...options,
          headers: {
            'Authorization': `Bearer ${token}`,
            'Content-Type': 'application/json',
            ...options.headers
          },
          credentials: 'include'
        });

        if (!response.ok) {
          const errorData = await response.json();
          if (response.status === 401 && state.refreshToken) {
            const refreshResponse = await fetch(`${config.apiBaseUrl}/refresh`, {
              method: 'POST',
              headers: { 'Content-Type': 'application/json' },
              body: JSON.stringify({ refreshToken: state.refreshToken }),
              credentials: 'include'
            });

            if (refreshResponse.ok) {
              const { accessToken } = await refreshResponse.json();
              document.cookie = `accessToken=${accessToken}; maxAge=900; path=/`;
              state.token = accessToken;
              options.headers = { ...options.headers, 'Authorization': `Bearer ${accessToken}` };
              return await fetch(`${config.apiBaseUrl}${url}`, options);
            }
          }
          throw {
            status: response.status,
            message: errorData.error || 'Request failed'
          };
        }

        return await response.json();
      } catch (error) {
        utils.handleApiError(error);
        throw error;
      }
    }
  };

  const core = {
    showLoginView: () => {
      elements.appBody.classList.add('login-body');
      elements.loginView.classList.remove('hidden');
      elements.dashboardView.classList.add('hidden');
      elements.emailInput.focus();
    },

    showDashboardView: () => {
      elements.appBody.classList.remove('login-body');
      elements.loginView.classList.add('hidden');
      elements.dashboardView.classList.remove('hidden');
      core.initTheme();
      core.initNavigation();
      core.initSessionChecker();
    },

    verifySession: async () => {
      const token = utils.getCookie('accessToken') || state.token;
      const refreshToken = utils.getCookie('refreshToken') || state.refreshToken;
      console.log('Verifying session:', { token, refreshToken });

      if (!token && !refreshToken) {
        state.isAuthenticated = false;
        core.showLoginView();
        return false;
      }

      try {
        const response = await utils.fetchWithAuth('/profile');
        state.user = response.profile;
        state.personnelDetails = response.profile.personnel || null;

        if (!state.personnelDetails) {
          const storedDetails = localStorage.getItem('abccompanyempdetails');
          if (storedDetails) {
            state.personnelDetails = JSON.parse(storedDetails);
            utils.showAlert('warning', 'Using personnel details from localStorage');
          } else {
            utils.showAlert('warning', 'No employee details received from server');
          }
        } else {
          localStorage.setItem('abccompanyempdetails', JSON.stringify(state.personnelDetails));
          utils.showAlert('success', 'Employee details successfully saved to localStorage');
          utils.logToServer('Stored personnel details in localStorage', 'info');
        }

        state.token = token;
        state.isAuthenticated = true;

        setTimeout(() => {
          elements.avatarSkeleton.style.display = 'none';
          elements.userAvatar.style.display = 'block';
          elements.userAvatar.src = state.user.profile_image || 
            'https://img.icons8.com/fluency/48/user-male-circle.png';
          elements.userName.textContent = state.user.username || 'User';
          elements.userName.style.opacity = 0;
          setTimeout(() => {
            elements.userName.style.transition = 'opacity 0.3s ease';
            elements.userName.style.opacity = 1;
          }, 50);
        }, 800);

        core.showDashboardView();
        return true;
      } catch (error) {
        if (refreshToken && error.status === 401) {
          try {
            const refreshResponse = await fetch(`${config.apiBaseUrl}/refresh`, {
              method: 'POST',
              headers: { 'Content-Type': 'application/json' },
              body: JSON.stringify({ refreshToken }),
              credentials: 'include'
            });

            if (refreshResponse.ok) {
              const { accessToken } = await refreshResponse.json();
              document.cookie = `accessToken=${accessToken}; maxAge=900; path=/`;
              state.token = accessToken;
              return await core.verifySession();
            }
          } catch (refreshError) {
            console.error('Refresh token failed:', refreshError);
            utils.logToServer(`Refresh token failed: ${refreshError.message}`, 'error');
          }
        }
        localStorage.removeItem('abccompanyempdetails');
        sessionStorage.removeItem('user');
        document.cookie = 'accessToken=; Max-Age=0; path=/;';
        document.cookie = 'refreshToken=; Max-Age=0; path=/;';
        state.isAuthenticated = false;
        state.user = null;
        state.token = null;
        state.refreshToken = null;
        state.personnelDetails = null;
        core.showLoginView();
        return false;
      }
    },

    initTheme: () => {
      const prefersDark = window.matchMedia('(prefers-color-scheme: dark)').matches;
      const savedTheme = localStorage.getItem('theme');
      state.isDarkMode = savedTheme === 'dark' || (!savedTheme && prefersDark);
      if (state.isDarkMode) {
        document.body.classList.add('dark-mode');
        elements.themeToggle.innerHTML = '<i class="material-icons">light_mode</i>';
      } else {
        elements.themeToggle.innerHTML = '<i class="fas fa-moon"></i>';
      }

      elements.themeToggle.addEventListener('click', () => {
        state.isDarkMode = !state.isDarkMode;
        document.body.classList.toggle('dark-mode');
        elements.themeToggle.innerHTML = state.isDarkMode
          ? '<i class="material-icons">light_mode</i>'
          : '<i class="fas fa-moon"></i>';
        localStorage.setItem('theme', state.isDarkMode ? 'dark' : 'light');
      });
    },

    sendEmpDataToIframe: (() => {
      let lastSent = 0;
      const debounceTime = 1000; // 1 second
      return () => {
        const now = Date.now();
        if (now - lastSent < debounceTime) return;
        lastSent = now;
        const empData = localStorage.getItem('abccompanyempdetails');
        const iframe = elements.contentFrame;
        if (empData && iframe && iframe.contentWindow) {
          try {
            const targetOrigin = new URL(iframe.src).origin;
            iframe.contentWindow.postMessage(
              { 
                type: 'EMP_DETAILS', 
                data: {
                  emp: JSON.parse(empData),
                  accessToken: state.token
                }
              },
              targetOrigin
            );
            console.log(`Sent emp details to iframe: ${targetOrigin}`);
            utils.logToServer(`Sent emp details to iframe: ${targetOrigin}`, 'debug');
            utils.showAlert('success', `Employee details sent to module at ${targetOrigin}`);
          } catch (e) {
            console.error('Error sending postMessage:', e);
            utils.logToServer(`Error sending postMessage: ${e.message}`, 'error');
            utils.showAlert('error', 'Failed to send employee details to module');
          }
        } else {
          console.warn('No emp data or iframe not ready');
          utils.logToServer('No emp data or iframe not ready for postMessage', 'warn');
        }
      };
    })(),

    initNavigation: () => {
      const allowedIframeOrigins = Object.values(config.modules)
        .filter(url => url && url.startsWith('http'))
        .map(url => new URL(url).origin)
        .filter((value, index, self) => self.indexOf(value) === index);

      window.addEventListener('message', (event) => {
        if (!allowedIframeOrigins.includes(event.origin)) {
          console.warn(`Blocked message from unauthorized origin: ${event.origin}`);
          utils.logToServer(`Blocked message from unauthorized origin: ${event.origin}`, 'warn');
          return;
        }
        if (event.data && event.data.type === 'REQUEST_EMP_DETAILS') {
          console.log(`Received data request from iframe: ${event.origin}`);
          utils.logToServer(`Received data request from iframe: ${event.origin}`, 'debug');
          core.sendEmpDataToIframe();
        }
      });

      const positionMenuItems = (menu, numItems) => {
        const radius = 150;
        const angleStep = 360 / numItems;
        menu.querySelectorAll('.menu-item').forEach((item, index) => {
          const angle = index * angleStep - 90;
          const rad = angle * (Math.PI / 180);
          const x = radius * Math.cos(rad);
          const y = radius * Math.sin(rad);
          item.style.left = `calc(50% + ${x}px - 20px)`;
          item.style.top = `calc(50% + ${y}px - 20px)`;
        });
      };

      positionMenuItems(elements.empMenu, elements.empMenu.querySelectorAll('.menu-item').length);
      positionMenuItems(elements.hrMenu, elements.hrMenu.querySelectorAll('.menu-item').length);

      const showMenu = (menuType) => {
        console.log(`Showing menu: ${menuType}`);
        elements.empMenu.classList.remove('active');
        elements.hrMenu.classList.remove('active');
        if (menuType === 'emp') {
          elements.empMenu.classList.add('active');
        } else if (menuType === 'hr') {
          elements.hrMenu.classList.add('active');
        }
        state.currentMenu = menuType;
        elements.moduleSelector.value = menuType;
      };

      elements.moduleSelector.addEventListener('change', (event) => {
        event.stopPropagation();
        const module = event.target.value;
        console.log(`Dropdown selected: ${module}`);
        showMenu(module);
      });

      [elements.empMenu, elements.hrMenu].forEach(menu => {
        menu.querySelectorAll('.menu-item').forEach(item => {
          item.addEventListener('click', (event) => {
            event.stopPropagation();
            const module = item.dataset.module;
            console.log(`Module clicked: ${module}`);
            if (module === 'emp_logout' || module === 'hr_logout') {
              core.handleLogout();
              return;
            }
            if (config.modules[module]) {
              elements.contentFrame.style.opacity = '0.5';
              elements.contentFrame.style.transition = 'opacity 0.3s ease';
              setTimeout(() => {
                elements.contentFrame.src = config.modules[module];
                elements.contentFrame.onload = () => {
                  elements.contentFrame.style.opacity = '1';
                  core.sendEmpDataToIframe();
                };
              }, 200);
            } else {
              console.warn(`No URL found for module: ${module}`);
              utils.showAlert('error', `Module ${module} not found`);
            }
            elements.radialMenu.classList.add('closing');
            elements.radialMenu.classList.remove('active');
            document.body.classList.remove('menu-open');
            showMenu('emp');
            setTimeout(() => {
              elements.radialMenu.classList.remove('closing');
              elements.toggleBtn.disabled = false;
              state.isToggling = false;
            }, 1000);
          });
        });
      });

      elements.toggleBtn.addEventListener('click', (event) => {
        event.stopPropagation();
        if (state.isToggling) return;
        state.isToggling = true;
        elements.toggleBtn.disabled = true;
        elements.radialMenu.classList.toggle('active');
        document.body.classList.toggle('menu-open');
        if (elements.radialMenu.classList.contains('active')) {
          showMenu('emp');
        } else {
          elements.radialMenu.classList.add('closing');
          setTimeout(() => {
            elements.radialMenu.classList.remove('closing');
            elements.toggleBtn.disabled = false;
            state.isToggling = false;
          }, 1000);
        }
        setTimeout(() => {
          elements.toggleBtn.disabled = false;
          state.isToggling = false;
        }, 1000);
      });

      elements.infoIcon.addEventListener('click', () => {
        if (state.personnelDetails) {
          elements.empName.textContent = state.personnelDetails.name || 'N/A';
          elements.empEmail.textContent = state.personnelDetails.email || 'N/A';
          elements.empId.textContent = state.personnelDetails.emp_id || 'N/A';
          elements.empDepartment.textContent = state.personnelDetails.department || 'N/A';
          elements.empRole.textContent = state.personnelDetails.job_role || 'N/A';
          elements.empDetailsModal.style.display = 'flex';
        } else {
          utils.showAlert('error', 'No employee details available');
        }
      });

      elements.modalClose.addEventListener('click', () => {
        elements.empDetailsModal.style.display = 'none';
      });

      document.addEventListener('click', (event) => {
        if (elements.radialMenu.classList.contains('active') && 
            !elements.radialMenu.contains(event.target) && 
            !elements.toggleBtn.contains(event.target)) {
          console.log('Closing menu due to outside click');
          if (state.isToggling) return;
          state.isToggling = true;
          elements.toggleBtn.disabled = true;
          elements.radialMenu.classList.add('closing');
          elements.radialMenu.classList.remove('active');
          document.body.classList.remove('menu-open');
          showMenu('emp');
          setTimeout(() => {
            elements.radialMenu.classList.remove('closing');
            elements.toggleBtn.disabled = false;
            state.isToggling = false;
          }, 1000);
        }
        if (!elements.searchBar.contains(event.target)) {
          elements.autocompleteDropdown.style.display = 'none';
        }
        if (elements.empDetailsModal.style.display === 'flex' && 
            !elements.empDetailsModal.querySelector('.modal-content').contains(event.target) && 
            !elements.infoIcon.contains(event.target)) {
          elements.empDetailsModal.style.display = 'none';
        }
      });

      elements.moduleSelector.addEventListener('click', (event) => {
        event.stopPropagation();
      });

      // Trigger postMessage on iframe load
      elements.contentFrame.addEventListener('load', core.sendEmpDataToIframe);

      // Observe iframe src changes
      const observer = new MutationObserver(() => core.sendEmpDataToIframe());
      observer.observe(elements.contentFrame, { attributes: true, attributeFilter: ['src'] });

      // Search functionality
      const moduleNames = {
        emp_attendance: { name: 'Attendance', icon: 'https://img.icons8.com/color/24/calendar--v1.png' },
        emp_leave: { name: 'Leave', icon: 'https://img.icons8.com/color/24/beach.png' },
        emp_wfh: { name: 'WFH', icon: 'https://img.icons8.com/color/24/laptop.png' },
        emp_payslip: { name: 'Payslip', icon: 'https://img.icons8.com/color/24/money-bag.png' },
        emp_tasks: { name: 'Tasks', icon: 'https://img.icons8.com/color/24/task-completed.png' },
        emp_helpdesk: { name: 'Help Desk', icon: 'https://img.icons8.com/color/24/help.png' },
        emp_Onboarding: { name: 'Onboarding', icon: 'https://cdn-icons-png.freepik.com/256/13730/13730909.png?semt=ais_hybrid' },
        emp_benefits: { name: 'Benefits', icon: 'https://cdn-icons-png.flaticon.com/512/8655/8655563.png' },
        emp_Appraisal: { name: 'Appraisal', icon: 'https://cdn-icons-png.flaticon.com/512/12278/12278438.png' },
        emp_notifications: { name: 'Notifications', icon: 'https://cdn-icons-png.flaticon.com/512/4658/4658755.png' },
        emp_asset: { name: 'Assets', icon: 'https://cdn-icons-png.flaticon.com/512/3135/3135771.png' },
        emp_bonus: { name: 'Bonus', icon: 'https://cdn-icons-png.flaticon.com/512/6303/6303173.png' },
        emp_joblists: { name: 'Job Listings', icon: 'https://cdn-icons-png.flaticon.com/512/4116/4116684.png' },
        emp_claim: { name: 'Claims', icon: 'https://cdn-icons-png.flaticon.com/512/12194/12194787.png' },
        emp_offboarding: { name: 'Offboarding', icon: 'https://cdn-icons-png.freepik.com/256/8265/8265009.png?semt=ais_hybrid' },
        emp_jobapplication: { name: 'Job Application', icon: 'https://cdn-icons-png.flaticon.com/512/13441/13441753.png' },
        emp_offerletter: { name: 'Offer Letter', icon: 'https://cdn-icons-png.freepik.com/256/4654/4654143.png?semt=ais_hybrid' },
        hr_attendance: { name: 'Attendance', icon: 'https://img.icons8.com/color/24/calendar--v1.png' },
        hr_leave: { name: 'Leave', icon: 'https://img.icons8.com/color/24/beach.png' },
        hr_wfh: { name: 'WFH', icon: 'https://img.icons8.com/color/24/laptop.png' },
        hr_payslip: { name: 'Payslip', icon: 'https://img.icons8.com/color/24/money-bag.png' },
        hr_tasks: { name: 'Tasks', icon: 'https://img.icons8.com/color/24/task-completed.png' },
        hr_helpdesk: { name: 'Help Desk', icon: 'https://img.icons8.com/color/24/help.png' },
        hr_employeemanagement: { name: 'Employee Management', icon: 'https://img.icons8.com/color/24/conference-call.png' },
        hr_benefits: { name: 'Benefits', icon: 'https://cdn-icons-png.flaticon.com/512/11113/11113093.png' },
        hr_appraisal: { name: 'Appraisal', icon: 'https://cdn-icons-png.flaticon.com/512/11112/11112856.png' },
        hr_notifications: { name: 'Notifications', icon: 'https://img.icons8.com/color/24/appointment-reminders.png' },
        hr_asset: { name: 'Assets', icon: 'https://img.icons8.com/color/24/feedback.png' },
        hr_bonus: { name: 'Bonus', icon: 'https://img.icons8.com/color/24/document.png' },
        hr_joblists: { name: 'Job Listings', icon: 'https://img.icons8.com/color/24/training.png' },
        hr_claim: { name: 'Claims', icon: 'https://cdn-icons-png.freepik.com/256/14252/14252153.png?semt=ais_hybrid' },
        hr_offboarding: { name: 'Offboarding', icon: 'https://img.icons8.com/?size=192&id=E1XHpaUoWFxv&format=png' },
        hr_jobapplication: { name: 'Job Application', icon: 'https://cdn-icons-png.flaticon.com/512/16995/16995294.png' },
        hr_Onboarding: { name: 'Onboarding', icon: 'https://cdn-icons-png.flaticon.com/512/3862/3862949.png' }
      };

      const performSearch = (query) => {
        if (query.length < 3) {
          elements.autocompleteDropdown.style.display = 'none';
          return;
        }
        elements.autocompleteDropdown.innerHTML = '';
        const results = Object.entries(moduleNames).filter(([key, module]) => 
          module.name.toLowerCase().includes(query.toLowerCase())
        );
        if (results.length === 0) {
          const noResults = document.createElement('div');
          noResults.className = 'no-results';
          noResults.textContent = 'No module found';
          elements.autocompleteDropdown.appendChild(noResults);
          elements.autocompleteDropdown.style.display = 'block';
          return;
        }
        results.forEach(([moduleKey, module]) => {
          const item = document.createElement('div');
          item.className = 'autocomplete-item';
          item.innerHTML = `<img src="${module.icon}" alt="${module.name}"><span>${module.name}</span>`;
          item.dataset.module = moduleKey;
          item.addEventListener('click', () => {
            if (config.modules[moduleKey]) {
              elements.contentFrame.style.opacity = '0.5';
              elements.contentFrame.style.transition = 'opacity 0.3s ease';
              setTimeout(() => {
                elements.contentFrame.src = config.modules[moduleKey];
                elements.contentFrame.onload = () => {
                  elements.contentFrame.style.opacity = '1';
                  core.sendEmpDataToIframe();
                };
              }, 200);
              elements.autocompleteDropdown.style.display = 'none';
              elements.searchInput.value = '';
            } else {
              utils.showAlert('error', `Module ${module.name} not found`);
            }
          });
          elements.autocompleteDropdown.appendChild(item);
        });
        elements.autocompleteDropdown.style.display = 'block';
      };

      elements.searchInput.addEventListener('input', (event) => {
        performSearch(event.target.value.trim());
      });

      elements.searchButton.addEventListener('click', () => {
        performSearch(elements.searchInput.value.trim());
      });

      elements.searchInput.addEventListener('keypress', (event) => {
        if (event.key === 'Enter') {
          performSearch(elements.searchInput.value.trim());
        }
      });
    },

    initSessionChecker: () => {
      setInterval(async () => {
        if (state.isAuthenticated) {
          await core.verifySession();
        }
      }, config.sessionCheckInterval);
    },

    handleLogout: () => {
      fetch(`${config.apiBaseUrl}/logout`, {
        method: 'POST',
        credentials: 'include'
      })
      .then(() => {
        localStorage.removeItem('abccompanyempdetails');
        sessionStorage.removeItem('user');
        document.cookie = 'accessToken=; Max-Age=0; path=/;';
        document.cookie = 'refreshToken=; Max-Age=0; path=/;';
        state.isAuthenticated = false;
        state.user = null;
        state.token = null;
        state.refreshToken = null;
        state.personnelDetails = null;
        utils.showAlert('success', 'Logged out successfully');
        core.showLoginView();
      })
      .catch(err => {
        utils.handleApiError(err);
      });
    },

    validateForm: () => {
      const email = elements.emailInput.value.trim();
      const password = elements.passwordInput.value;
      elements.errorMessage.textContent = '';
      const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

      if (!email) {
        elements.errorMessage.textContent = 'Email is required';
        return false;
      }
      if (!emailRegex.test(email)) {
        elements.errorMessage.textContent = 'Invalid email format';
        return false;
      }
      if (!password) {
        elements.errorMessage.textContent = 'Password is required';
        return false;
      }
      if (password.length < 8) {
        elements.errorMessage.textContent = 'Password must be at least 8 characters';
        return false;
      }

      return true;
    },

    handleLogin: async (e) => {
      e.preventDefault();
      if (!core.validateForm()) return;

      const email = elements.emailInput.value.trim();
      const password = elements.passwordInput.value;
      elements.loginButton.disabled = true;
      elements.loginButton.innerHTML = '<i class="fas fa-spinner fa-spin"></i> Logging in...';

      try {
        const response = await fetch(`${config.apiBaseUrl}/login`, {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          credentials: 'include',
          body: JSON.stringify({ email, password })
        });

        const data = await response.json();

        if (response.ok) {
          if (data.accessToken) {
            document.cookie = `accessToken=${data.accessToken}; maxAge=900; path=/`;
            state.token = data.accessToken;
          }
          if (data.refreshToken) {
            document.cookie = `refreshToken=${data.refreshToken}; maxAge=604800; path=/`;
            state.refreshToken = data.refreshToken;
          }
          if (data.user) {
            sessionStorage.setItem('user', JSON.stringify(data.user));
            state.user = data.user;
          }
          if (data.personnel) {
            localStorage.setItem('abccompanyempdetails', JSON.stringify(data.personnel));
            state.personnelDetails = data.personnel;
            utils.showAlert('success', 'Employee details successfully saved to localStorage');
            utils.logToServer('Stored personnel details after login', 'info');
          } else {
            utils.showAlert('warning', 'No employee details received from server');
            utils.logToServer('No personnel details received during login', 'warn');
          }
          state.isAuthenticated = true;
          utils.showAlert('success', 'Login successful! Redirecting...');
          await core.verifySession();
        } else {
          elements.errorMessage.textContent = data.error || 'Login failed';
          utils.showAlert('error', data.error || 'Login failed');
          utils.logToServer(`Login failed: ${data.error || 'Unknown error'}`, 'error');
          elements.passwordInput.value = '';
        }
      } catch (err) {
        console.error('Login error:', err);
        elements.errorMessage.textContent = 'Error connecting to server';
        utils.showAlert('error', 'Error connecting to server');
        utils.logToServer(`Login error: ${err.message}`, 'error');
      } finally {
        elements.loginButton.disabled = false;
        elements.loginButton.textContent = 'Login';
      }
    },

    togglePassword: () => {
      if (elements.passwordInput.type === 'password') {
        elements.passwordInput.type = 'text';
        elements.eyeIcon.className = 'fas fa-eye-slash eye-icon';
      } else {
        elements.passwordInput.type = 'password';
        elements.eyeIcon.className = 'fas fa-eye eye-icon';
      }
    }
  };

  const init = async () => {
    const isAuthenticated = await core.verifySession();
    if (isAuthenticated) {
      utils.showAlert('success', `Welcome back, ${state.user.username || 'User'}!`);
      utils.logToServer(`User ${state.user.email} session verified`, 'info');
      core.sendEmpDataToIframe();
    } else {
      core.showLoginView();
      elements.eyeIcon.addEventListener('click', core.togglePassword);
      elements.loginForm.addEventListener('submit', core.handleLogin);
    }
  };

  init();
});
</script>
    
    </body>
    </html>

